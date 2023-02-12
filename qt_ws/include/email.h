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
    bool setAccount(std::string id, std::string passwd);
    bool setReceiver(std::string receiver);
    bool setEmail(std::string title, std::string content);
    bool sendEmail();
private:
    std::vector<std::string> tokenizing(std::string str, std::string delimiters);

    std::string id_;
    std::string passwd_;
    std::string receiver_;
    std::string email_;
    bool is_account_registered_;
    bool are_addrs_ready_;
    bool is_data_ready_;
};