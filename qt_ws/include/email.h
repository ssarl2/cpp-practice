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
    Email(std::string id, std::string pwd);
    ~Email();
    void changeAccount(std::string id, std::string pwd);
    bool registerAccount(std::string id, std::string pwd);
    bool setAddrs(std::string from_addr, std::string to_addr);
    bool setData();
    bool setSSL();
    bool sendEmail();
    static size_t payload_source(char *ptr, size_t size, size_t nmemb, void *userp);
private:
    std::vector<std::string> tokenizing(std::string str, std::string delimiters);
    struct upload_status
    {
        size_t bytes_read;
    };
    CURL *curl_;
    struct curl_slist *recipients_;

    std::string id_;
    std::string pwd_;
    std::string from_addr_;
    std::string to_addr_;
    std::string from_mail_;
    std::string to_mail_;
    std::string payload_text_;
    // char *payload_text_;
    bool is_account_registered_;
    bool is_recipient_ready_;
    bool is_content_ready_;
    bool is_ssl_set_;
};