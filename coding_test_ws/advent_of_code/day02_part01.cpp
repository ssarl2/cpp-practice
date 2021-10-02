// https://adventofcode.com/2018/day/2

#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

int main(int argc, char *argv[])
{
    std::map<char,int> find_same_char;
    std::string line;
    int appear_two_times = 0;
    int appear_three_times = 0;
    // int c=0; //* debug

    std::ifstream* contents = new std::ifstream("../input/day02_input01.txt");

    //* parse lines
    while(*contents >> line)
    {
        // std::cout << c++ << ", " << line << std::endl; //* debug
        find_same_char.clear();

        //* parse and count each letters
        for (std::size_t i = 0; i < line.size(); i++)
        {
            // std::cout << line[i] << std::endl; //* debug
            std::map<char,int>::iterator it = find_same_char.find(line[i]);

            if(it==find_same_char.end())
            {
                find_same_char.insert(std::pair<char,int>(line[i],1));
                // std::cout << "Cound't find : " << line[i] << std::endl; //* debug
            }
            else
            {
                it->second++;
                // std::cout << "Found : " << it->first << ", " << it->second << std::endl; //* debug
            }
        }

        //* count multiple appearing times
        std::map<char,int>::const_iterator it;
        it = std::find_if(find_same_char.cbegin(), find_same_char.cend(), [&](const std::pair<char,int>& pair){return (pair.second == 2) ? true : false;});
        if(it->second)
        {
            appear_two_times++;
        }
        it = std::find_if(find_same_char.cbegin(), find_same_char.cend(), [&](const std::pair<char,int>& pair){return (pair.second == 3) ? true : false;});
        if(it->second)
        {
            appear_three_times++;
        }
        // std::cout << "appear_two_times : " << appear_two_times << std::endl; //* debug
    }

    std::cout << "appear_two_times : " << appear_two_times << std::endl;
    std::cout << "appear_three_times : " << appear_three_times << std::endl;

    std::cout << "A checksum : " << appear_two_times * appear_three_times << std::endl;

    return 0;
}