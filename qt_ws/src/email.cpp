#include "email.h"
#include <iostream>
#include <sstream>
#include <ctime>

struct data_struct
{
    std::string data;
    size_t pos = 0;
};
// https://github.com/yodasoda1219/web-server-test/blob/93d536bb6d7d0e62127d806ac566203a70ac047b/gui-client/src/util.cpp
static size_t payload_source(char* buffer, size_t size, size_t nitems, data_struct* data)
{
    std::string to_write = data->data.substr(data->pos, nitems * size);
    size_t bytes_written = 0;
    for (size_t i = 0; i < to_write.length(); i++)
    {
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

bool Email::setAccount(std::string id, std::string passwd)
{
    if(id.empty() || passwd.empty())
    {
        std::cout << "Either ID or password is empty!" << std::endl;
        return false;
    }

    id_ = id;
    passwd_ = passwd;
    return true;
}


bool Email::setReceiver(std::string receiver)
{
    if(receiver.empty())
    {
        std::cout << "Receiver is empty!" << std::endl;
        return false;
    }

    receiver_ = receiver;
    return true;
}

bool Email::setEmail(std::string subject, std::string content)
{
    if(subject.empty() || content.empty())
    {
        std::cout << "Either title or content is empty!" << std::endl;
        return false;
    }

    const std::string WEEKDAY[]={"Sun","Mon","Tue", "Wed","Thu","Fri","Sat"};
    const std::string MONTH[]={"Jan","Feb","Mar", "Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

    std::time_t t = std::time(0);
    std::tm *now = std::localtime(&t);

    std::stringstream ss;

    if(id_.empty() || receiver_.empty())
    {
        std::cout << "Failed to set data! Addrs are not set." << std::endl;
        return false;
    }
    std::string sender_name = tokenizing(id_, "@")[0];
    std::string receiver_name = tokenizing(receiver_, "@")[0];
    
    ss
    << "Date: "<< WEEKDAY[now->tm_wday] << ", " << now->tm_mday << " " << MONTH[now->tm_mon] << " " << now->tm_year + 1900 << " " << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec << " " << " +0000\r\n"
    << "To: " << receiver_name << " " << receiver_ << "\r\n"
    << "From: " << sender_name << " " << id_ << "\r\n"
    << "Subject: " << subject << "\r\n"
    << "\r\n"
    << content << "\r\n";

    email_ = ss.str();
    return true;
}

bool Email::sendEmail()
{

    data_struct read;
    read.data = email_;
    CURL *curl;
    curl = curl_easy_init();
    if(curl)
    {
        std::string account = id_+std::string(":")+passwd_;
        curl_easy_setopt(curl, CURLOPT_USERPWD, account.c_str());
        curl_easy_setopt(curl, CURLOPT_URL, "smtp://smtp.gmail.com:587");

        curl_easy_setopt(curl, CURLOPT_MAIL_FROM, id_.c_str());
        curl_slist *recipients = NULL;
        recipients = curl_slist_append(recipients, receiver_.c_str());
        curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);

        curl_easy_setopt(curl, CURLOPT_READFUNCTION, payload_source);
        curl_easy_setopt(curl, CURLOPT_READDATA, &read);
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
    }
    return true;
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