// https://www.acmicpc.net/problem/1085

#include <iostream>

int main()
{
    int x, y, w, h;
    std::cin >> x >> y >> w >> h;
    auto comp = [](int a, int b) { return a > b ? b : a; };
    std::cout << comp(comp(w - x, x), comp(h - y, y)) << std::endl;

    return 0;
}