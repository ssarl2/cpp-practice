// https://www.acmicpc.net/problem/10951

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int A = 0;
    int B = 0;

    while (1)
    {
        std::cin >> A >> B;
        if (std::cin.eof())
        {
            break;
        }
        std::cout << A + B << '\n';
    }

    return 0;
}