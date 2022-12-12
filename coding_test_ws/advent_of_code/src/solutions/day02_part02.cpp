// https://adventofcode.com/2018/day/2

#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char *argv[])
{
    std::string line;
    std::vector<std::string> lines;
    int count_different_letters = 0;
    bool found = false;

    std::ifstream* contents = new std::ifstream(argv[1]);

    //* parse lines
    while(*contents >> line)
    {
        // std::cout << c++ << ", " << line << std::endl; //* debug
        lines.push_back(line);
    }

    //* begin a main line
    for (std::size_t i = 0; i < lines.size()-1; i++)
    {
        if(found)
        {
            break;
        }

        //* begin lines that will be compared with the main line
        for (std::size_t j = i+1; j < lines.size(); j++)
        {
            count_different_letters = 0;

            //* start comparing each letters
            for (std::size_t k = 0; k < line.size(); k++)
            {
                //* between two lines
                if(count_different_letters > 1)
                {
                    break;
                }

                if(lines[i][k]!=lines[j][k])
                {
                    count_different_letters++;
                }
            }

            if(count_different_letters == 1)
            {
                std::cout << i << ", " << lines[i] << std::endl;
                std::cout << j << ", " << lines[j] << std::endl;

                if(found)
                {
                    break;
                }
            }

        }
    }

    return 0;
}