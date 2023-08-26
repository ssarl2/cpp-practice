// https://www.acmicpc.net/problem/24313

#include <iostream>

int main()
{
    int fn1, fn2, c, n;
    std::cin >> fn1 >> fn2 >> c >> n;

    while ((fn1 * n + fn2) <= (c * n))
    {
        if (n > 100)
        {
            std::cout << 1 << std::endl;
            return 0;
        }
        n++;
    }
    std::cout << 0 << std::endl;

    return 0;
}