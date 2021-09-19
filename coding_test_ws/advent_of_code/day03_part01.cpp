https://adventofcode.com/2018/day/3

#include <iostream>
#include <fstream>
#include <vector>

class Claim
{
public:
    Claim(std::string claim);
    ~Claim();
    void print_fabric();
private:
    void parse_claim(std::string claim);
    int x_from_left;
    int y_from_bottom;
    int width_fabric;
    int height_fabric;
};

int main(int argc, char *argv[])
{
    std::string line;
    std::ifstream* contents = new std::ifstream("../input/day03_input01.txt");
    std::vector<Claim> claims;

    //* parse lines
    while(*contents >> line)
    {
        Claim claim{line};
        claims.push_back(claim);
    }

    //* create n claim objects
    //  * details of the object
    //  * a variable of x for the starting point
    //  * a variable of y for the starting point
    //  * a variable of the fabric width
    //  * a variable of the fabric height
    //  * a function of printing a fabric (when it prints, reverse y value)
    //* compare all each objects
    //  * a function of comparing two claims whether they overlap
    //    * check two of width of objects from the starting point whether they overlap and loop as much as height
    //    * calculate overlapped part of rectangles and save it for the result

    return 0;
}