// https://www.acmicpc.net/problem/27866

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    char c[1001];
    int  n = 0;

    std::cin.getline(c, 1001);
    std::cin >> n;

    std::cout << c[n - 1] << "\n";

    return 0;
}