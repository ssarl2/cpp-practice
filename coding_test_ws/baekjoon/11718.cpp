// https://www.acmicpc.net/problem/11718

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    char line[102];

    while (std::cin.getline(line, sizeof(line)))
    {
        std::cout << line << '\n';
        if (std::cin.eof())
        {
            break;
        }
    }

    return 0;
}