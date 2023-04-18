// https://www.acmicpc.net/problem/11720

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int  N;
    int  sum = 0;
    char c;
    std::cin >> N;
    std::cin.ignore();

    for (size_t i = 0; i < N; i++)
    {
        std::cin >> c;
        sum += static_cast<int>(c) - 48;
    }

    std::cout << sum << "\n";

    return 0;
}