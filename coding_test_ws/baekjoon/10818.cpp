#include <iostream>

#define EQUAL true
#define EXCEED false

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
    unsigned N = userInput(1, EQUAL, 1000000, EQUAL);

    int max = -1000000;
    int min = 1000000;
    for (unsigned i = 0; i < N; i++)
    {
        int in = userInput(-1000000, EQUAL, 1000000, EQUAL);
        if (in > max)
        {
            max = in;
        }
        if (in < min)
        {
            min = in;
        }
    }

    int* results = (int*)malloc(2 * sizeof(int));
    results[0]   = min;
    results[1]   = max;

    return results;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int* min_and_max = solution();

    std::cout << min_and_max[0] << " " << min_and_max[1] << "\n";

    free(min_and_max);

    return 0;
}