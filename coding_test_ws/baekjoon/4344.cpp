// https://www.acmicpc.net/problem/4344

#include <iomanip>
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int    C;
    int    N;
    int    sum;
    double over_avg;

    std::cin >> C;

    for (int i = 0; i < C; i++)
    {
        sum      = 0;
        over_avg = 0;
        std::cin >> N;
        double score[N];
        for (int j = 0; j < N; j++)
        {
            std::cin >> score[j];
            sum += score[j];
        }

        for (int j = 0; j < N; j++)
        {
            if (score[j] > static_cast<double>(sum) / static_cast<double>(N))
            {
                over_avg++;
            }
        }

        std::cout << std::fixed << std::setprecision(3)
                  << over_avg / static_cast<double>(N) * 100.0 << "%\n";
    }

    return 0;
}