// https://www.acmicpc.net/problem/2292

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N = 0;
    std::cin >> N;

    int x = 1;
    int i = 1;
    while (1)
    {
        if (N < x + 1)
            break;
        x = x + 6 * i++;
    }

    std::cout << i << "\n";
    return 0;
}