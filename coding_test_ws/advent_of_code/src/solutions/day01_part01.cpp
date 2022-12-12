// https://adventofcode.com/2018/day/1

#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {

    std::ifstream infile(argv[1]);
    int sum, i;
    sum = 0;

    while(infile >> i)
    {
        std::cout << i << ", ";
        sum += i;
    }

    std::cout << std::endl << "Sum result : " << sum << std::endl;

    return 0;
}
