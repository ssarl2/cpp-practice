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

    for (size_t i = 1; i < len; i++)
    {
        if (S[i] == ' ' && S[i + 1] != '\0')
        {
            count++;
        }
    }

    if (len > 1)
    {
        std::cout << count << '\n';
    }
    else
    {
        std::cout << count - 1 << '\n';
    }

    return 0;
}