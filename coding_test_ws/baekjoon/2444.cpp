// https://www.acmicpc.net/problem/2444

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int s;
    std::cin >> s;
    int white_space = s;
    for (int i = 1; i < s * 2; i++)
    {
        /*
         * 0 == white space
         * s = 3
         * 3 - 1 = 2    00
         * 3 - 2 = 1    0
         * 3 - 3 = 0
         * 3 - 4 = 1    0
         * 3 - 5 = 2    00
         */
        white_space = s - i >= 0 ? s - i : -1 * (s - i);

        for (int j = 0; j < white_space; j++)
        {
            std::cout << " ";
        }

        for (int j = 0; j < (s - white_space - 1) * 2 + 1; j++)
        {
            std::cout << "*";
        }

        std::cout << "\n";
    }

    return 0;
}