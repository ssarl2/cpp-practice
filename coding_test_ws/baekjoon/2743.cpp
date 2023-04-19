// https://www.acmicpc.net/problem/2743

#include <iostream>
#include <cstring>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    char c[101];

    std::cin.getline(c, 101);

    std::cout << strlen(c) << "\n";

    return 0;
}