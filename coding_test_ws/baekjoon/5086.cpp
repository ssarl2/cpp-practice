// https://www.acmicpc.net/problem/5086

#include <iostream>

int main()
{
    int A, B;

    while (1)
    {
        std::cin >> A >> B;
        if (A == 0 && B == 0)
            break;

        if (A == 0 || B == 0)
        {
            std::cout << "neither\n";
            continue;
        }

        if (A % B == 0)
            std::cout << "multiple\n";
        else if (B % A == 0)
            std::cout << "factor\n";
        else
            std::cout << "neither\n";
    }

    return 0;
}