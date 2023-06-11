// https://www.acmicpc.net/problem/2501

#include <iostream>

int main()
{
    int p, q;
    std::cin >> p >> q;

    int i = 0;
    while (1)
    {
        i++;
        if (p % i == 0)
            q--;

        if (q == 0)
            break;

        if (i > p)
        {
            i = 0;
            break;
        }
    }
    std::cout << i;

    return 0;
}