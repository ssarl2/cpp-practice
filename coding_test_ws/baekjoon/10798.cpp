// https://www.acmicpc.net/problem/10798

#include <cstring>
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    char arr[5][17];
    int  max_len = 0;

    memset(arr, '\0', sizeof(arr));

    for (int i = 0; i < 5; i++)
    {
        std::cin.getline(arr[i], sizeof(arr[i]));
        if (strlen(arr[i]) > max_len)
        {
            max_len = strlen(arr[i]);
        }
    }

    for (int i = 0; i < max_len; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[j][i] == '\0')
            {
                continue;
            }
            std::cout << arr[j][i];
        }
    }

    std::cout << "\n";

    return 0;
}