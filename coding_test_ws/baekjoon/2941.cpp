// https://www.acmicpc.net/problem/2941

#include <cstring>
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    char word[102];
    std::cin >> word;
    int len = strlen(word);

    char tmp = 0;
    for (int i = 0; i < len / 2; i++)
    {
        tmp               = word[i];
        word[i]           = word[len - i - 1];
        word[len - i - 1] = tmp;
    }

    int count = 0;
    for (int i = 0; i < len; i++)
    {
        count++;
        if (word[i] == '=')
        {
            if (word[i + 1] == 'c')
            {
                i += 1;
            }
            else if (word[i + 1] == 'z')
            {
                if (word[i + 2] == 'd')
                {
                    i += 2;
                }
                else
                {
                    i += 1;
                }
            }
            else if (word[i + 1] == 's')
            {
                i += 1;
            }
        }
        else if (word[i] == '-')
        {
            if (word[i + 1] == 'c')
            {
                i += 1;
            }
            else if (word[i + 1] == 'd')
            {
                i += 1;
            }
        }
        else if (word[i] == 'j')
        {
            if (word[i + 1] == 'l')
            {
                i += 1;
            }
            else if (word[i + 1] == 'n')
            {
                i += 1;
            }
        }
    }

    std::cout << count << "\n";

    return 0;
}