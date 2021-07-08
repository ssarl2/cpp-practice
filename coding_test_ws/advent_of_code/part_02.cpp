// https://adventofcode.com/2018/day/1

#include <iostream>
#include <fstream>
#include <set>

int main(int argc, char *argv[]) {
    std::set<int> std_set;
    int sum = 0, i = 0, x;

    bool found = false;
    while(!found)
    {
        std::ifstream infile("../input/input01.txt");
        while(infile >> x)
        {
            sum += x;
            std::cout << sum << std::endl;

            // set doesn't allow to have duplicated values. This is a way to find a value existing.
            if(std_set.find(sum) != std_set.end())
            {
                std::cout << "Duplicated!" << std::endl;
                found = true;
                break;
            }
            std_set.insert(sum);
            i++;
        }
    }

    std::cout << "index : " << i << std::endl;
    std::cout << std::endl << "Sum result : " << sum << std::endl;

    return 0;
}
