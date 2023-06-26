// https://www.acmicpc.net/problem/24267

#include <iostream>

int main()
{
    long long int n;
    std::cin >> n;
    long long int equation = (n - 2) * (n - 1) * n / 6;
    std::cout << equation << "\n" << 3 << std::endl;
    return 0;
}

/*
 * I don't know how to get the equation
 * Someone used Sigma,
 * Someone used Probability and Statistics - Combination
 */
