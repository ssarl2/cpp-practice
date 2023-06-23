// https://www.acmicpc.net/problem/5073

#include <algorithm>
#include <iostream>

int main()
{
    int A, B, C, longest = 0;

    while (1)
    {
        std::cin >> A >> B >> C;
        if (A == B && B == C && C == 0)
            break;

        longest = std::max(std::max(A, B), C);

        if ((A + B + C) - longest <= longest)
            std::cout << "Invalid" << std::endl;
        else if (A == B && B == C)
            std::cout << "Equilateral" << std::endl;
        else if (A == B || A == C || B == C)
            std::cout << "Isosceles" << std::endl;
        else if (A != B && A != C && B != C)
            std::cout << "Scalene" << std::endl;
    }

    return 0;
}