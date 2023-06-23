// https://www.acmicpc.net/problem/9063

#include <iostream>

int main()
{
    int N, X, Y;
    std::cin >> N;
    if (N == 1)
    {
        std::cin >> X >> Y;
        std::cout << 0 << std::endl;
        return 0;
    }

    int x1, x2, y1, y2;
    x1 = y1 = 10000;
    x2 = y2 = -10000;
    for (int i = 0; i < N; i++)
    {
        std::cin >> X >> Y;
        if (X > x2)
            x2 = X;
        if (X < x1)
            x1 = X;
        if (Y > y2)
            y2 = Y;
        if (Y < y1)
            y1 = Y;
    }

    std::cout << (x2 - x1) * (y2 - y1) << std::endl;

    return 0;
}