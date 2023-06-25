// https://www.acmicpc.net/problem/24265

#include <iostream>

int main()
{
    long long int n;
    std::cin >> n;
    std::cout << n * (n - 1) / 2 << "\n" << 2 << std::endl;
    return 0;
}