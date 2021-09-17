https://adventofcode.com/2018/day/3

#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    std::string lines;
    std::ifstream* contents = new std::ifstream("../input/day03_input01.txt");

    //* parse lines
    while(*contents >> line)
    {
        lines.push_back(line);
    }

    //* create n claim objects
    //  * details of the object
    //  * ..
    //* compare all each objects
    //* calculate overlapped part of rectangles and save it for the result

    return 0;
}