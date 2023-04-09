// https://www.acmicpc.net/problem/10810

#include <iostream>

#define EQUAL true
#define EXCEED false
#define LESS false

bool inputCondition(int in, int c_min, bool c1, int c_max, bool c2)
{
    if (c1 && c2)
    {
        return c_min <= in && in <= c_max;
    }
    else if (c1)
    {
        return c_min <= in && in < c_max;
    }
    else if (c2)
    {
        return c_min < in && in <= c_max;
    }
    else
    {
        return c_min < in && in < c_max;
    }
}

int userInput(int c_min, bool c1, int c_max, bool c2)
{
    std::cin.tie(NULL);
    int ins;
    do
    {
        std::cin >> ins;
    } while (!inputCondition(ins, c_min, c1, c_max, c2));

    return ins;
}

void solution()
{
    int N          = userInput(1, EQUAL, 100, EQUAL);
    int M          = userInput(1, EQUAL, 100, EQUAL);
    int baskets[N] = {0};

    for (int i = 0; i < M; i++)
    {
        int I = userInput(1, EQUAL, N, EQUAL);
        int J = userInput(I, EQUAL, N, EQUAL);
        int K = userInput(1, EQUAL, N, EQUAL);
        for (int j = I - 1; j < J; j++)
        {
            baskets[j] = K;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (baskets[i] == 0)
        {
            std::cout << "0"
                      << " ";
        }
        else
        {
            std::cout << baskets[i] << " ";
        }
    }
    std::cout << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    solution();

    return 0;
}