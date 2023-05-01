// https://www.acmicpc.net/problem/1316

#include <cstring>
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int group[(int)'z' - (int)'a' + 1];

    int N;
    std::cin >> N;
    std::cin.ignore();

    char word[102];
    int count = N;
    int len = 0;
    for (int i = 0; i < N; i++)
    {
        memset(group, 0, sizeof(group));

        std::cin >> word;
        len = strlen(word);
        for (int j = 0; j < len; j++)
        {
            if (word[j] == word[j - 1])
            {
                continue;
            }

            if (group[(int)word[j] - (int)'a'])
            {
                count--;
                break;
            }
            else
            {
                group[(int)word[j] - (int)'a']++;
            }
        }
    }

    std::cout << count << "\n";

    return 0;
}