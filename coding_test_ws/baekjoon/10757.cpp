// https://www.acmicpc.net/problem/10757

#include <algorithm>
#include <iostream>
#include <string>

int addTwoStrings(char A, char B, int up)
{
    std::string a{A};
    std::string b{B};
    int         x = std::stoi(a) + std::stoi(b) + up;
    return x;
}

void appendIntWithUp(std::string& target, int& i, int& up)
{
    if (i > 9)
    {
        up = 1;
        i -= 10;
    }
    else
    {
        up = 0;
    }

    target.append(std::to_string(i));
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string A, B, res;

    std::cin >> A >> B;
    int A_len = A.length(), B_len = B.length();

    std::reverse(A.begin(), A.end());
    std::reverse(B.begin(), B.end());
    int x  = 0;
    int up = 0;
    for (int i = 0; i < std::min(A_len, B_len); i++)
    {
        x = addTwoStrings(A.front(), B.front(), up);
        A.erase(0, 1);
        B.erase(0, 1);
        appendIntWithUp(res, x, up);
    }

    std::string X;
    if (!A.empty())
        X = A;
    else if (!B.empty())
        X = B;

    while (!X.empty())
    {
        x = addTwoStrings(X.front(), '0', up);
        X.erase(0, 1);
        appendIntWithUp(res, x, up);
    }

    if (up != 0)
        res.append("1");

    std::reverse(res.begin(), res.end());

    std::cout << res << "\n";

    return 0;
}