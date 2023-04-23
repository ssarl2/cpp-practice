// https://www.acmicpc.net/problem/5622

#include <cstring>
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int  time = 0;
    char word[16];
    int  ascii;

    std::cin >> word;

    for (int i = 0; i < strlen(word); i++)
    {
        ascii = static_cast<int>(word[i]);

        time += (ascii - 56) / 3;
        if ((ascii - 80) / 3 > 0 && (ascii - 80) % 3 == 0)
        {
            time--;
        }
        if (ascii == static_cast<int>('Z'))
        {
            time--;
        }
    }
    std::cout << time << '\n' << std::flush;

    return 0;
}