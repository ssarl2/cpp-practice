// https://adventofcode.com/2018/day/1

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>

int main(int argc, char *argv[]) {

    std::unordered_set<int> find_same_sum;
    int sum = 0, i = 0, file_loaded = 0, x;
    int file_stored = 200;

    std::vector<std::ifstream *> predefined_files;
    for (std::size_t i = 0; i < file_stored; i++)
    {
        std::ifstream* f = new std::ifstream("../input/input01.txt");
        predefined_files.push_back(f);
    }

    bool found = false;
    while(!found)
    {
        if(file_loaded==file_stored)
            break;
        while(*predefined_files[file_loaded] >> x)
        {
            sum += x;
            std::cout << "sum : " << sum << std::endl;

            // set doesn't allow to have duplicated values. This is a way to find a value existing.
            if(find_same_sum.find(sum) != find_same_sum.end())
            {
                std::cout << "Duplicated!" << std::endl;
                found = true;
                break;
            }
            find_same_sum.insert(sum);
            i++;
        }
            std::cout << "fine_loaded " << file_loaded << " times" << std::endl;
        file_loaded++;
    }

    std::cout << "sum " << i << " times" << std::endl;
    std::cout << "\nSum result : " << sum << std::endl;

    // clear vector with one of below way
    {
        predefined_files.clear();
        predefined_files.shrink_to_fit();
        std::vector<std::ifstream *>().swap(predefined_files);
    }
    // clear unordered_set with one of below way
    {
        find_same_sum.rehash(0);
        // std::unordered_set<int>().swap(find_same_sum);
    }

    return 0;
}
