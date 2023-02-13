// https://curl.se/libcurl/c/smtp-mail.html
#ifndef __EMAIL_H__
#define __EMAIL_H__

#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <ctime>

#include <curl/curl.h>

class Email
{
public:
    Email();
    ~Email();
    bool setAccount(std::string id, std::string app_pwd);
    bool setReceiver(std::string receiver);
    bool setEmail(std::string subject, std::string content);
    bool sendEmail();
private:
    std::vector<std::string> tokenizing(std::string str, std::string delimiters);

    std::string id_;
    std::string app_pwd_;
    std::string receiver_;
    std::string email_;
};
#endif // __EMAIL_H__
