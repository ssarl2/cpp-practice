// https://www.acmicpc.net/problem/10809

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int  position  = -1;
    int  alphabets = static_cast<int>('z') - static_cast<int>('a') + 1;
    int  n[alphabets];
    char word[101];
    std::cin >> word;
    std::cin.ignore();

    for (int i = 0; i < alphabets; i++)
    {
        n[i] = -1;
    }

    for (int i = 0; i < alphabets; i++)
    {
        for (int j = 0; word[j] != '\0'; j++)
        {
            position = static_cast<int>(word[j]) - static_cast<int>('a');
            if (position > -1 && n[position] == -1)
            {
                n[position] = j;
                break;
            }
        }
    }

    for (int i = 0; i < alphabets; i++)
    {
        std::cout << n[i] << " ";
    }

    std::cout << "\n";

    return 0;
}