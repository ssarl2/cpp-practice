// https://www.acmicpc.net/problem/1978

#include <algorithm>
#include <iostream>
#include <vector>

void deleteMultiples(std::vector<int>& target, int multiple)
{
    int multiples = multiple;
    while (multiples < target.back())
    {
        multiples += multiple;
        auto it = std::find(target.begin(), target.end(), multiples);
        if (it != target.end())
            target.erase(it);
    }
}

std::vector<int> getPrimeNumbers(int number)
{
    std::vector<int> numbers(number - 1);
    for (int i = 1; i < number; i++)
        numbers[i - 1] = i + 1;

    auto it = numbers.begin();
    while (it != numbers.end())
    {
        deleteMultiples(numbers, *it);
        it++;
    }

    return numbers;
}

int main()
{
    std::vector<int> primeNumbers = getPrimeNumbers(1000);

    int N;
    std::cin >> N;

    int p;
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        std::cin >> p;
        if (std::find(primeNumbers.begin(), primeNumbers.end(), p) !=
            primeNumbers.end())
            count++;
    }

    std::cout << count << std::endl;

    return 0;
}