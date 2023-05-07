// https://www.acmicpc.net/problem/2738

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;

    std::cin >> N >> M;

    int arr[2][N][M];

    for (int n = 0; n < 2; n++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                std::cin >> arr[n][i][j];
            }
        }
    }

    int res[N][M];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            res[i][j] = arr[0][i][j] + arr[1][i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}