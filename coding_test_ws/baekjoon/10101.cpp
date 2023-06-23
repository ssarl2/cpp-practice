// https://www.acmicpc.net/problem/10101

#include <iostream>

int main()
{
    int A, B, C;
    std::cin >> A >> B >> C;

    if (A == B && B == C && C == 60)
        std::cout << "Equilateral";
    else if ((A + B + C) == 180)
    {
        if (A == B || A == C || B == C)
            std::cout << "Isosceles";
        else
            std::cout << "Scalene";
    }
    else
        std::cout << "Error";

    return 0;
}