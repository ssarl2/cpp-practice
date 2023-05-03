// https://www.acmicpc.net/problem/2566

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int max = 0;
    int row = 0, col = 0;
    int num = 0;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            std::cin >> num;
            if (num > max)
            {
                max = num;
                row = i;
                col = j;
            }
        }
    }

    std::cout << max << "\n" << row + 1 << " " << col + 1 << "\n";

    return 0;
}