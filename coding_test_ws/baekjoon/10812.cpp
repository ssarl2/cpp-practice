// https://www.acmicpc.net/problem/10812

#include <cstring>
#include <iostream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    std::cin >> N >> M;
    std::cin.ignore();

    int arr[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = i + 1;
    }

    int tmp[N];
    memset(tmp, 0, sizeof(tmp));

    int begin, mid, end;
    int mid_to_end_size;
    int tmp_size;
    int new_begin;
    for (int i = 0; i < M; i++)
    {
        std::cin >> begin >> end >> mid;
        mid_to_end_size = end - mid + 1;
        tmp_size        = mid - begin;
        new_begin       = begin + mid_to_end_size - 1;

        for (int x = 0, y = begin - 1; y < mid - 1; x++)
        {
            tmp[x] = arr[y++];
        }
        for (int x = begin - 1, y = mid - 1; x < begin + mid_to_end_size - 1;
             x++)
        {
            arr[x] = arr[y++];
        }
        for (int x = new_begin, y = 0; x < new_begin + tmp_size; x++)
        {
            arr[x] = tmp[y++];
        }
    }

    for (int i = 0; i < N; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << "\n";

    return 0;
}