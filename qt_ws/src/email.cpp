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


static const char *payload_text =
"Date: Tue, 07 Feb 2023 01:23:12 +1100\r\n"
"To: " TO_MAIL "\r\n"
"From: " FROM_MAIL "\r\n"
"Cc: \r\n"
"Message-ID: <dcd7cb36-11db-487a-9f3a-e652a9458efd@"
"rfcpedant.example.org>\r\n"
"Subject: SMTP example message\r\n"
"\r\n"
"The body of the message starts here.\r\n"
"\r\n"
"It could be a lot of lines, could be MIME encoded, whatever.\r\n"
"Check RFC5322.\r\n";

// struct upload_status
// {
//     size_t bytes_read;
// };

// static size_t payload_source(char *ptr, size_t size, size_t nmemb, void *userp)
// {
//     struct upload_status *upload_ctx = (struct upload_status *)userp;
//     const char *data;
//     size_t room = size*nmemb;

//     if((size == 0) || (nmemb == 0) || ((size*nmemb) < 1))
//     {
//         return 0;
//     }

//     std::cout << "payload data" << std::endl;
//     std::cout << upload_ctx->bytes_read << std::endl;
//     data = &payload_text[upload_ctx->bytes_read];
//     if(data)
//     {
//         size_t len = strlen(data);
//         if(room < len)
//             len = room;
//         memcpy(ptr, data, len);
//         upload_ctx->bytes_read += len;
//         std::cout << len << std::endl;
//         std::cout << ptr << std::endl;

//         return len;
//     }

//     return 0;
// }

struct data_struct {
    std::string data;
    size_t pos = 0;
};

static size_t payload_source(char* buffer, size_t size, size_t nitems, data_struct* data) {
    std::string to_write = data->data.substr(data->pos, nitems * size);
    size_t bytes_written = 0;
    for (size_t i = 0; i < to_write.length(); i++) {
        buffer[i] = to_write[i];
        bytes_written++;
    }
    data->pos += bytes_written;
    return bytes_written;
}

Email::Email()
{
}

Email::~Email()
{}


// static const char *payload_text;
std::string payload_text_("");

bool Email::setData()
{
    // struct upload_status upload_ctx = { 0 };


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

    // payload_text = payload_text_.c_str();

    // std::cout << "Data" << std::endl;
    // std::cout << payload_text << std::endl;


}

bool Email::sendEmail()
{
    bool d = setData();
    data_struct read, write;
    read.data = payload_text_;
    std::cout << "sendEmail" << std::endl;
    CURL *curl;
    curl = curl_easy_init();
    // struct upload_status upload_ctx = { 0 };
    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_USERPWD, "sender@gmail.com:apppassword");
        // curl_easy_setopt(curl, CURLOPT_USERNAME, "sender@gmail.com");
        // curl_easy_setopt(curl, CURLOPT_USERPWD, "apppassword");
        curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.gmail.com:587");

        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, FROM_ADDR);
        curl_slist *recipients = NULL;
        recipients = curl_slist_append(recipients, TO_ADDR);
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
        std::cout << "before setData" << std::endl;
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);
        curl_easy_setopt(curl, CURLOPT_READDATA, &read);
        // curl_easy_setopt(curl, CURLOPT_READDATA, &upload_ctx);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        // curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

        curl_easy_setopt(curl, CURLOPT_USE_SSL, CURLUSESSL_ALL);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0);

        CURLcode res = curl_easy_perform(curl);

        if(res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            curl_slist_free_all(recipients);
            curl_easy_cleanup(curl);
            return false;
        }
        curl_slist_free_all(recipients);
        curl_easy_cleanup(curl);
        return true;
    }
}



std::vector<std::string> Email::tokenizing(std::string str, std::string delimiters)
{
    std::vector<std::string> tokens;

    while(true)
    {
        // find frontest token in delimiters
        long int frontest = std::string::npos;
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