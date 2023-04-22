// https://www.acmicpc.net/problem/1152

#include <cstring>
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int  count = 1;
    char S[1000002];
    std::cin.getline(S, sizeof(S));
    size_t len = strlen(S);

    for (size_t i = 0; i < len; i++)
    {
        if (S[i] == ' ')
        {
            count++;
        }
    }

    if (S[0] == ' ')
    {
        count--;
    }
    if (S[len - 1] == ' ')
    {
        count--;
    }

    std::cout << count << '\n';

    return 0;
}