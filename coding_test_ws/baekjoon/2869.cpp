// https://www.acmicpc.net/problem/2869

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int A, B, V;
    std::cin >> A >> B >> V;
    int days = 1 + (V - A) / (A - B);
    if (((V - A) % (A - B)) != 0)
        days++;

    std::cout << days << "\n";
    return 0;
}