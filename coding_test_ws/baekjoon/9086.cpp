// https://www.acmicpc.net/problem/9086

#include <cstring>
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int  n   = 0;
    int  len = 0;
    char c[1001];

    std::cin >> n;
    std::cin.ignore();

    for (size_t i = 0; i < n; i++)
    {
        std::cin.getline(c, 1001);
        len = strlen(c);

        std::cout << c[0];
        if (len < 2)
        {
            std::cout << c[0];
        }
        else
        {
            std::cout << c[len - 1];
        }
        std::cout << "\n";
    }

    return 0;
}