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

std::vector<std::string> tools::readFileAsVecStr(char* file_path)
{
    std::string line;
    std::vector<std::string> lines;

    std::ifstream* contents = new std::ifstream(file_path);

    //* parse lines
    while(std::getline(*contents, line))
    {
        lines.push_back(line);
    }

    return lines;
}

std::vector<std::string> tools::tokenizing(std::string str, std::string delimiters)
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

std::map<int,int>::iterator tools::minMapElement(std::map<int,int>& m)
{
    return std::min_element(m.begin(), m.end(),
        [](std::map<int,int>::value_type& l, std::map<int,int>::value_type& r) -> bool
        {
            if(l.second == -1 || r.second == -1)
                return false;
            return l.second < r.second;
        });
}

int tools::countValues(std::map<int,int>& m, int value)
{
    std::vector<int> v;
    for(const auto &c : m)
    {
        v.push_back(c.second);
    }
    return std::count(v.begin(), v.end(), value);
}

int tools::countValues(std::map<std::pair<int,int>,int>& m, int value)
{
    std::vector<int> v;
    for(const auto &c : m)
    {
        v.push_back(c.second);
    }
    return std::count(v.begin(), v.end(), value);
}