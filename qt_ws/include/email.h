// https://curl.se/libcurl/c/smtp-mail.html

#include <curl/curl.h>
#include <string>
#include <cstring>
#include <vector>

#define FROM_ADDR  "sender@gmail.com"
#define TO_ADDR  "receiver@gmail.com"
#define FROM_MAIL  "libcurlc++ "  FROM_ADDR
#define TO_MAIL  "receiver "  TO_ADDR

class Email
{
public:
    Email();
    ~Email();
    bool setData();
    bool sendEmail();
private:
    std::vector<std::string> tokenizing(std::string str, std::string delimiters);

    std::string id_;
    std::string pwd_;
    std::string from_addr_;
    std::string to_addr_;
    std::string from_mail_;
    std::string to_mail_;
    std::string payload_text_;
    // static const char *payload_text;
    bool is_account_registered_;
    bool is_recipient_ready_;
    bool is_content_ready_;
    bool is_ssl_set_;
};