#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

namespace tools
{
enum debug_level
{
    no = 0,
    normal = 1,
    debug = 2
};

void log(debug_level level, std::string log);

// Comparator function to sort pairs
// according to second value
bool cmp(std::pair<std::string, std::string>& a,
         std::pair<std::string, std::string>& b);

// Function to sort the map according
// to value in a (key-value) pairs
void sort(std::map<std::string, std::string>& M);
}
