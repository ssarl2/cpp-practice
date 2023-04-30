// https://www.acmicpc.net/problem/2908

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    char a[4];
    char b[4];

    std::cin >> a >> b;

    for (size_t i = 2; i >= 0; i--)
    {
        if (a[i] > b[i])
        {
            std::cout << a[2] << a[1] << a[0] << "\n";
            break;
        }
        else if (a[i] < b[i])
        {
            std::cout << b[2] << b[1] << b[0] << "\n";
            break;
        }
    }

    return 0;
}