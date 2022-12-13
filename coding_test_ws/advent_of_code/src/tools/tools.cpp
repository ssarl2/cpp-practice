#include <tools.h>

void tools::log(debug_level level, std::string log)
{
    if (level == no)
    {
        return;
    }
    else
    {
        if(level == normal)
        {
            std::cout << log << std::endl;
        }
        else if(level == debug)
        {
            std::cout << log << std::endl;
        }
        else
        {
            std::cout << "Not supporting printing method" << std::endl;
        }
    }
}

bool tools::cmp(std::pair<std::string, std::string>& a,
         std::pair<std::string, std::string>& b)
{
    return a.first < b.first;
}

void tools::sort(std::map<std::string, std::string>& M)
{
    // Declare vector of pairs
    std::vector<std::pair<std::string, std::string>> A;

    // Copy key-value pair from Map
    // to vector of pairs
    for (auto &it : M)
    {
        A.push_back(it);
    }

    // Sort using comparator function
    std::sort(A.begin(), A.end(), cmp);
}