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

unsigned* solution()
{
    unsigned require       = userInput(1, EQUAL, 10000, EQUAL);
    int      target        = userInput(1, EQUAL, 10000, EQUAL);
    int*     arr           = (int*)malloc(require * sizeof(int));
    unsigned count_targets = 0;

    for (unsigned i = 0; i < require; i++)
    {
        arr[i] = userInput(1, EQUAL, 10000, EQUAL);
    }

    for (unsigned i = 0; i < require; i++)
    {
        if (arr[i] < target)
        {
            count_targets++;
        }
    }

    unsigned* result =
        (unsigned*)malloc((count_targets + 1) * sizeof(unsigned));
    int n = 0;
    for (unsigned i = 0; i < require; i++)
    {
        if (arr[i] < target)
        {
            result[n++] = arr[i];
        }
    }
    result[count_targets] = 0;

    free(arr);

    return result;
}

int main()
{
    std::ios::sync_with_stdio(false);
    unsigned* arr = solution();
    unsigned  n   = 0;
    while (arr[n] != 0)
    {
        std::cout << arr[n++] << " ";
    }
    std::cout << "\n";

    free(arr);

    return 0;
}