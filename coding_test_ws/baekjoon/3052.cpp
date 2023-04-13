// https://www.acmicpc.net/problem/3052

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int arr[10] = {0};
    int n       = 0;
    int result  = 10;

    for (int i = 0; i < 10; i++)
    {
        std::cin >> n;
        arr[i] = n % 42;
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (arr[i] == arr[j])
            {
                result--;
                break;
            }
        }
    }

    std::cout << result << "\n";

    return 0;
}