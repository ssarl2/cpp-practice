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

int solution()
{
    unsigned require = userInput(1, EQUAL, 100, EQUAL);
    int      arr[require];
    unsigned result = 0;

    for (unsigned i = 0; i < require; i++)
    {
        arr[i] = userInput(-100, EQUAL, 100, EQUAL);
    }

    unsigned search = userInput(-100, EQUAL, 100, EQUAL);
    for (unsigned i = 0; i < require; i++)
    {
        if (arr[i] == search)
        {
            result++;
        }
    }

    return result;
}

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    std::cout << solution() << "\n";
    return 0;
}