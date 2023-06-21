// https://www.acmicpc.net/problem/3009

#include <iostream>

int main()
{
    int x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int x4 = 0, y4 = 0;
    if (x1 == x2)
        x4 = x3;
    else if (x1 == x3)
        x4 = x2;
    else if (x2 == x3)
        x4 = x1;

    if (y1 == y2)
        y4 = y3;
    else if (y1 == y3)
        y4 = y2;
    else if (y2 == y3)
        y4 = y1;

    std::cout << x4 << " " << y4 << std::endl;

    return 0;
}