// https://www.acmicpc.net/problem/1193

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int X;
    std::cin >> X;

    int numerator, denominator, i, prev_i, diff;
    numerator = denominator = i = prev_i = diff = 0;

    int n = 1;
    while (1)
    {
        i = n * (n - 1) / 2 + 1;
        if (i == X)
        {
            numerator   = 1;
            denominator = n;
            break;
        }
        else if (i > X)
        {
            diff        = X - prev_i;
            numerator   = 1 + diff;
            denominator = n - 1 - diff;
            n--;
            break;
        }
        prev_i = i;
        n++;
    }

    if (n % 2 == 0)
        std::cout << numerator << "/" << denominator << "\n";
    else
        std::cout << denominator << "/" << numerator << "\n";

    return 0;
}