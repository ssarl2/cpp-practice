// https://www.acmicpc.net/problem/14215

#include <algorithm>
#include <iostream>

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;

    int longest   = std::max(std::max(a, b), c);
    int other_two = (a + b + c) - longest;

    int res = 0;
    if (other_two <= longest)
        res = other_two * 2 - 1;
    else
        res = a + b + c;

    std::cout << res;

    return 0;
}