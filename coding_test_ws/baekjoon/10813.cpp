// https://www.acmicpc.net/problem/10813

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    std::cin >> N >> M;
    int baskets[N];
    for (int i = 0; i < N; i++)
    {
        baskets[i] = i + 1;
    }

    int b1, b2, tmp;
    for (int i = 0; i < M; i++)
    {
        std::cin >> b1 >> b2;
        tmp             = baskets[b1 - 1];
        baskets[b1 - 1] = baskets[b2 - 1];
        baskets[b2 - 1] = tmp;
    }

    for (int i = 0; i < N; i++)
    {
        std::cout << baskets[i] << " ";
    }
    std::cout << "\n";

    return 0;
}