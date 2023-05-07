// https://www.acmicpc.net/problem/11005

#include <iostream>

void print(int n)
{
    if (n < 10)
    {
        std::cout << n;
    }
    else
    {
        std::cout << static_cast<char>(static_cast<int>('A') + n - 10);
    }
}

void convert(int N, int B)
{
    if (N / B == 0)
    {
        print(N % B);
        return;
    }
    convert(N / B, B);
    print(N % B);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, B;
    std::cin >> N >> B;
    convert(N, B);
    std::cout << "\n";

    return 0;
}