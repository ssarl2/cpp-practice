// https://www.acmicpc.net/problem/10811

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N = 0;
    int M = 0;
    std::cin >> N >> M;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = i + 1;
    }

    int tmp = 0;
    int a   = 0;
    int b   = 0;
    for (int i = 0; i < M; i++)
    {
        std::cin >> a >> b;
        for (int x = a, y = b; x < 1 + (a + b) / 2; x++, y--)
        {
            tmp        = arr[x - 1];
            arr[x - 1] = arr[y - 1];
            arr[y - 1] = tmp;
        }
    }

    for (int i = 0; i < N; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}