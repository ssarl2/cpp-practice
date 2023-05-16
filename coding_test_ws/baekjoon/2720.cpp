// https://www.acmicpc.net/problem/2720

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T, M;
    std::cin >> T;

    int Q, D, N, P;
    for (int i = 0; i < T; i++)
    {
        std::cin >> M;
        Q = M / 25;
        D = (M - Q * 25) / 10;
        N = (M - Q * 25 - D * 10) / 5;
        P = M - Q * 25 - D * 10 - N * 5;

        std::cout << Q << " " << D << " " << N << " " << P << "\n";
    }

    return 0;
}