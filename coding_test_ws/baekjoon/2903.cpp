// https://www.acmicpc.net/problem/2903

#include <iostream>

int own_pow(int b, int e)
{
    return (e == 0) ? 1 : b * own_pow(b, e - 1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N = 0;
    std::cin >> N;

    std::cout << own_pow((1 + own_pow(2, N)), 2) << "\n";

    return 0;
}