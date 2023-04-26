// https://www.acmicpc.net/problem/10988

#include <cstring>
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    char word[102];
    bool is_palindrome = true;

    std::cin >> word;
    int len = strlen(word);
    for (size_t i = 0; i < len; i++)
    {
        if (word[i] != word[len - i - 1])
        {
            is_palindrome = false;
            break;
        }
    }

    std::cout << (is_palindrome ? "1" : "0") << "\n";
    return 0;
}