// https://adventofcode.com/2018/day/2

#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

//* parse and count each letters
void parseAndCount(std::map<char,int>& find_same_char, std::string& line)
{
        for (std::size_t i = 0; i < line.size(); i++)
        {
            std::map<char,int>::iterator it = find_same_char.find(line[i]);

            if(it==find_same_char.end())
            {
                find_same_char.insert(std::pair<char,int>(line[i],1));
            }
            else
            {
                it->second++;
            }
        }
}

//* count multiple appearing times
bool countMultipleAppearingTimes(std::map<char,int>& find_same_char, int& appearing_times)
{
    std::map<char,int>::const_iterator it;
    it = std::find_if(find_same_char.cbegin(), find_same_char.cend(), [&](const std::pair<char,int>& pair){return (pair.second == appearing_times) ? true : false;});
    if(it->second == appearing_times)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(int argc, char *argv[])
{
    std::map<char,int> find_same_char;
    std::string line;
    int appearing_times = 0;
    int appear_two_times = 0;
    int appear_three_times = 0;

    std::ifstream* contents = new std::ifstream(argv[1]);

    //* process lines
    while(*contents >> line)
    {
        find_same_char.clear();

        parseAndCount(find_same_char, line);

        if(countMultipleAppearingTimes(find_same_char, appearing_times = 2))
        {
            appear_two_times++;
        }
        if(countMultipleAppearingTimes(find_same_char, appearing_times = 3))
        {
            appear_three_times++;
        }
    }

    std::cout << "appear_two_times : " << appear_two_times << std::endl;
    std::cout << "appear_three_times : " << appear_three_times << std::endl;

    std::cout << "A checksum : " << appear_two_times * appear_three_times << std::endl;

    return 0;
}