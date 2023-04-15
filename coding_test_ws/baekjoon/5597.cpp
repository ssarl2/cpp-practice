// https://www.acmicpc.net/problem/5597

#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int number_of_students           = 30;
    int students[number_of_students] = {0};

    int n;
    for (int i = 0; i < number_of_students - 2; i++)
    {
        std::cin >> n;
        students[n - 1] = 1;
    }

    for (int i = 0; i < number_of_students; i++)
    {
        if (students[i] == 0)
        {
            std::cout << i + 1 << "\n";
        }
    }

    return 0;
}