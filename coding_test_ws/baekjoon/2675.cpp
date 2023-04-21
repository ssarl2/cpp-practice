// https://www.acmicpc.net/problem/2675

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int  T = 0;
    int  R = 0;
    char S[21];
    std::cin >> T;
    std::cin.ignore();

    for (int i = 0; i < T; i++)
    {
        std::cin >> R >> S;
        for (int j = 0; S[j] != '\0'; j++)
        {
            for (int k = 0; k < R; k++)
            {
                std::cout << S[j];
            }
        }
        std::cout << "\n";
    }

    return 0;
}