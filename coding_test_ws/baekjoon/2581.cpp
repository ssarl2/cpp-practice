// https://www.acmicpc.net/problem/2581

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
    int M, N;
    std::cin >> M >> N;

    std::vector<int> primeNumbers = getPrimeNumbers(N);

    auto it = primeNumbers.begin();
    while (*it < M)
    {
        primeNumbers.erase(it);
        if (primeNumbers.size() == 0)
            break;
        it = primeNumbers.begin();
    }

    int sum = 0;
    for (const auto& p : primeNumbers)
        sum += p;

    if (primeNumbers.size() == 0)
        std::cout << -1 << std::endl;
    else
        std::cout << sum << std::endl << primeNumbers.front() << std::endl;

    return 0;
}