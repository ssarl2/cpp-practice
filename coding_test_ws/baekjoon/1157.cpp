// https://www.acmicpc.net/problem/1157

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int alphabet_size            = (int)'Z' - (int)'A' + 1;
    int alphabets[alphabet_size] = {0};
    int offset                   = (int)'a' - (int)'A';

    int  n                 = 0;
    int  highest_frequency = 0;
    char word[1000002];
    std::cin.getline(word, sizeof(word));
    for (int i = 0; word[i] != '\0'; i++)
    {
        n = (int)word[i] - (int)'a';
        if (n < 0)
        {
            n += offset;
        }

        alphabets[n]++;

        if (alphabets[n] > highest_frequency)
        {
            highest_frequency = alphabets[n];
        }
    }

    bool is_presented = false;
    for (int i = 0; i < alphabet_size; i++)
    {
        if (alphabets[i] == highest_frequency)
        {
            if (is_presented)
            {
                std::cout << "?\n";
                return 0;
            }
            is_presented = true;
        }
    }

    for (int i = 0; i < alphabet_size; i++)
    {
        if (alphabets[i] == highest_frequency)
        {
            std::cout << (char)(i + (int)'A') << "\n";
            return 0;
        }
    }

    return 0;
}