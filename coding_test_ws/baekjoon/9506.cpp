// https://www.acmicpc.net/problem/9506

#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> getPrimeFactors(int number)
{
    std::vector<int> numbers(number);
    for (int i = 0; i < number; i++)
        numbers[i] = i + 1;

    int i = 0;
    while (i < number)
    {
        i++;
        if (number % i != 0)
        {
            auto it = std::find(numbers.begin(), numbers.end(), i);
            numbers.erase(it);
        }
    }

    return numbers;
}

int main()
{
    int n;

    while (1)
    {
        std::cin >> n;
        if (n == -1)
            break;
        std::vector<int> res = getPrimeFactors(n);
        res.pop_back();

        int sum = -n;
        for (const auto& r : res)
            sum += r;

        printf("%d ", n);
        if (sum == 0)
        {
            auto front = res.begin();
            printf("= %d", *front);
            res.erase(front);
            for (const auto& r : res)
                printf(" + %d", *front++);
        }
        else
        {
            printf("is NOT perfect.");
        }
        printf("\n");
    }

    return 0;
}