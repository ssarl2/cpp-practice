// https://www.acmicpc.net/problem/1546

#include <iomanip>
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int    N     = 0;
    int    total = 0;
    double avg   = 0;
    int    max   = 0;
    int    in    = 0;

    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::cin >> in;
        total += in;
        if (in > max)
        {
            max = in;
        }
    }
    avg = static_cast<double>(total) / static_cast<double>(N);
    avg = avg / static_cast<double>(max) * 100.0;

    std::cout << std::fixed << std::setprecision(20) << avg << "\n";

    return 0;
}