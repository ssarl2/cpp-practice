#include "email.h"
#include <iostream>

// static const char *payload_text =
// "Date: Tue, 07 Feb 2023 01:23:12 +1100\r\n"
// "To: " TO_MAIL "\r\n"
// "From: " FROM_MAIL "\r\n"
// "Message-ID: <dcd7cb36-11db-487a-9f3a-e652a9458efd@"
// "rfcpedant.example.org>\r\n"
// "Subject: SMTP example message\r\n"
// "\r\n"
// "The body of the message starts here.\r\n"
// "\r\n"
// "It could be a lot of lines, could be MIME encoded, whatever.\r\n"
// "Check RFC5322.\r\n";


Email::Email(std::string id, std::string pwd)
: id_(id)
, pwd_(pwd)
, is_account_registered_(false)
, is_recipient_ready_(false)
, is_content_ready_(false)
, is_ssl_set_(false)
, recipients_(NULL)
{
    curl_ = curl_easy_init();
    is_account_registered_ = registerAccount(id, pwd);
}

Email::~Email()
{}

void Email::changeAccount(std::string id, std::string pwd)
{
    is_account_registered_ = registerAccount(id, pwd);
}

bool Email::registerAccount(std::string id, std::string pwd)
{
    std::cout << "registerAccount" << std::endl;
    std::string userpwd = id + std::string(":") + pwd;
    if(curl_)
    {
        curl_easy_setopt(curl_, CURLOPT_USERPWD, userpwd.c_str());

        return true;
    }

    return false;
}

bool Email::setAddrs(std::string from_addr, std::string to_addr)
{
    std::cout << "setAddrs" << std::endl;
    from_addr_ = from_addr;
    to_addr_ = to_addr;

    auto parse_from_addr = tokenizing(from_addr_, "@");
    auto parse_to_addr = tokenizing(to_addr_, "@");
    from_mail_ = parse_from_addr[0] + " " + from_addr;
    to_mail_ = parse_to_addr[0] + " " + to_addr;

    std::cout << "from_mail_ : " << from_mail_ << std::endl;
    std::cout << "to_mail_ : " << to_mail_ << std::endl;

    if(curl_)
    {
        recipients_ = curl_slist_append(recipients_, to_addr_.c_str());
        curl_easy_setopt(curl_, CURLOPT_MAIL_FROM, from_addr_.c_str());
        curl_easy_setopt(curl_, CURLOPT_MAIL_RCPT, recipients_);

        return true;
    }

    return false;
}

static const char *payload_text;

bool Email::setData()
{
    std::cout << "setData" << std::endl;
    struct upload_status upload_ctx = { 0 };

    if(!is_recipient_ready_)
    {
        return false;
    }

    payload_text_.append("Date: Tue, 07 Feb 2023 01:23:12 +1100\r\n");
    payload_text_.append(std::string("To: ") + to_mail_ + std::string("\r\n"));
    payload_text_.append(std::string("From: ") + from_mail_ + std::string("\r\n"));
    payload_text_.append("Message-ID: <dcd7cb36-11db-487a-9f3a-e652a9458efd@");
    payload_text_.append("rfcpedant.example.org>\r\n");
    payload_text_.append("Subject: SMTP example message\r\n");
    payload_text_.append("\r\n");
    payload_text_.append("The body of the message starts here.\r\n");
    payload_text_.append("\r\n");
    payload_text_.append("It could be a lot of lines, could be MIME encoded, whatever.\r\n");
    payload_text_.append("Check RFC5322.\r\n");

    payload_text = payload_text_.c_str();

    std::cout << "Data" << std::endl;
    // std::cout << payload_text << std::endl;


    // *payload_text_ =
    // "Date: Tue, 07 Feb 2023 01:23:12 +1100\r\n"
    // "To: " to_mail_ "\r\n"
    // "From: " from_mail_ "\r\n"
    // "Message-ID: <dcd7cb36-11db-487a-9f3a-e652a9458efd@"
    // "rfcpedant.example.org>\r\n"
    // "Subject: SMTP example message\r\n"
    // "\r\n"
    // "The body of the message starts here.\r\n"
    // "\r\n"
    // "It could be a lot of lines, could be MIME encoded, whatever.\r\n"
    // "Check RFC5322.\r\n";

    is_content_ready_ = true;

    if(curl_)
    {
        curl_easy_setopt(curl_, CURLOPT_READFUNCTION, Email::payload_source);
        curl_easy_setopt(curl_, CURLOPT_READDATA, &upload_ctx);

        return true;
    }

    return false;
}

bool Email::setSSL()
{
    std::cout << "setSSL" << std::endl;
    if(curl_)
    {
        curl_easy_setopt(curl_, CURLOPT_USE_SSL, CURLUSESSL_ALL);
        curl_easy_setopt(curl_, CURLOPT_SSL_VERIFYPEER, 0);

        return true;
    }

    return false;
}

bool Email::sendEmail()
{
    std::cout << "sendEmail" << std::endl;
    CURLcode res = CURLE_OK;
    struct upload_status upload_ctx = { 0 };
    struct curl_slist *recipients = NULL;

    if(curl_)
    {
        std::cout << "in curl" << std::endl;
        curl_easy_setopt(curl_, CURLOPT_URL, "smtp://smtp.gmail.com:587");
        std::cout << "after setopt" << std::endl;

        // is_recipient_ready_ = setAddrs("sender@gmail.com", "ssarl1180@gmail.com");

        // if(!is_recipient_ready_)
        // {
        //     return false;
        // }
        curl_easy_setopt(curl_, CURLOPT_MAIL_FROM, FROM_ADDR);
        // if(!is_account_registered_)
        // {
        //     return false;
        // }
        curl_easy_setopt(curl_, CURLOPT_USERPWD, "sender@gmail.com:apppassword");

        recipients = curl_slist_append(recipients, TO_ADDR);
        curl_easy_setopt(curl_, CURLOPT_MAIL_RCPT, recipients);

        std::cout << "before setData" << std::endl;
        bool is_Data_set = setData();
        if(!is_Data_set)
        {
            return false;
        }
        curl_easy_setopt(curl_, CURLOPT_READFUNCTION, payload_source);
        curl_easy_setopt(curl_, CURLOPT_READDATA, &upload_ctx);
        // curl_easy_setopt(curl_, CURLOPT_VERBOSE, 1);
        curl_easy_setopt(curl_, CURLOPT_UPLOAD, 1L);

        // bool is_SSL_set = setSSL();
        // if(!is_SSL_set)
        // {
        //     return false;
        // }
        curl_easy_setopt(curl_, CURLOPT_USE_SSL, CURLUSESSL_ALL);
        curl_easy_setopt(curl_, CURLOPT_SSL_VERIFYPEER, 0);

        res = curl_easy_perform(curl_);

        if(res != CURLE_OK)
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        curl_slist_free_all(recipients_);
        curl_easy_cleanup(curl_);
    }
    return true;
}

size_t Email::payload_source(char *ptr, size_t size, size_t nmemb, void *userp)
{
    std::cout << "payload_source" << std::endl;
    struct upload_status *upload_ctx = (struct upload_status *)userp;
    const char *data;
    size_t room = size*nmemb;

    if((size == 0) || (nmemb == 0) || ((size*nmemb) < 1))
    {
        return 0;
    }

    data = &payload_text[upload_ctx->bytes_read];

    if(data)
    {
        size_t len = strlen(data);
        if(room < len)
            len = room;
        memcpy(ptr, data, len);
        upload_ctx->bytes_read += len;

        return len;
    }

    return 0;
}


std::vector<std::string> Email::tokenizing(std::string str, std::string delimiters)
{
    std::vector<std::string> tokens;

    while(true)
    {
        // find frontest token in delimiters
        int frontest = std::string::npos;
        for(char d : delimiters)
        {
            std::size_t found = str.find(d);
            if(found < frontest)
            {
                frontest = found;
            }
        }

        std::string cut = str.substr(0, frontest);
        str.erase(0, frontest + 1);

        if(cut != "")
        {
            tokens.push_back(cut);
        }

        if(frontest == std::string::npos)
        {
            break;
        }
    }

    return tokens;
}