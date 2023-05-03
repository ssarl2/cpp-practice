// https://www.acmicpc.net/problem/2563

#include <cstring>
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int paper[100][100];
    memset(paper, 0, sizeof(paper));

    int num;
    std::cin >> num;

    int x, y;
    for (int i = 0; i < num; i++)
    {
        std::cin >> x >> y;
        for (int j = x; j < x + 10; j++)
        {
            for (int k = y; k < y + 10; k++)
            {
                paper[j][k] = 1;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            sum += paper[j][i];
        }
    }

    std::cout << sum << "\n";

    return 0;
}