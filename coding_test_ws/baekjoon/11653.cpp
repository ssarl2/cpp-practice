// https://www.acmicpc.net/problem/11653

#include <iostream>
#include <set>

int main()
{
    std::multiset<int> ms;

    int i = 1;
    int N;
    std::cin >> N;
    if (N == 1)
        return 0;

    while (1)
    {
        i++;
        if (N <= i)
        {
            ms.insert(i);
            break;
        }

        if (N % i == 0)
        {
            ms.insert(i);
            N = N / i;
            i = 1;
        }
    }

    for (const auto& x : ms)
        std::cout << x << std::endl;

    return 0;
}