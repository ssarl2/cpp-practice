// https://www.acmicpc.net/problem/2745

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string N;
    long int    B;
    long int    sum = 0;

    std::cin >> N >> B;
    std::reverse(N.begin(), N.end());

    int n = 0;
    for (int i = 0; i < N.size(); i++)
    {
        n = static_cast<int>(N[i]);
        if (n > 9)
        {
            n += 10 - static_cast<int>('A');
        }
        sum += (n * std::pow(B, i));
    }

    std::cout << sum << "\n";

    return 0;
}