// https://www.acmicpc.net/problem/2745

#include <algorithm>
#include <iostream>
#include <string>

int own_pow(int b, int e)
{
    return (e == 0) ? 1 : b * own_pow(b, e - 1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string N;
    int         B;
    int         sum = 0;

    std::cin >> N >> B;
    std::reverse(N.begin(), N.end());

    int n = 0;
    for (int i = 0; i < N.size(); i++)
    {
        n = N[i] - static_cast<int>('0');

        if (n > 9)
        {
            n = static_cast<int>(N[i]) - static_cast<int>('A') + 10;
        }
        sum += (n * own_pow(B, i));
    }

    if (sum <= 1000000000)
    {
        std::cout << sum << "\n";
    }

    return 0;
}