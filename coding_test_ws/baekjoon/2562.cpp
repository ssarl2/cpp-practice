// https://www.acmicpc.net/problem/2562

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

int* solution()
{
    int max      = 0;
    int location = 0;
    for (unsigned i = 0; i < 9; i++)
    {
        int in = userInput(1, EQUAL, 100, LESS);
        if (in > max)
        {
            max      = in;
            location = i + 1;
        }
    }

    int* results = (int*)malloc(2 * sizeof(int));
    results[0]   = max;      // max value
    results[1]   = location; // location of the value

    return results;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int* max_and_loc = solution();

    std::cout << max_and_loc[0] << "\n" << max_and_loc[1] << "\n";

    free(max_and_loc);

    return 0;
}