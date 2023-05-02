// https://www.acmicpc.net/problem/25206

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::string str;
    std::stringstream ss;

    std::string course_name;
    double grade;
    std::string score;

    double total_grade = 0.0;
    double total_score = 0.0;

    for (int i = 0; i < 20; i++)
    {
        std::getline(std::cin, str);
        ss.str(str);

        ss >> course_name >> grade >> score;
        ss.clear();

        if (score == "A+")
        {
            total_score += grade * 4.5;
        }
        else if (score == "A0")
        {
            total_score += grade * 4.0;
        }
        else if (score == "B+")
        {
            total_score += grade * 3.5;
        }
        else if (score == "B0")
        {
            total_score += grade * 3.0;
        }
        else if (score == "C+")
        {
            total_score += grade * 2.5;
        }
        else if (score == "C0")
        {
            total_score += grade * 2.0;
        }
        else if (score == "D+")
        {
            total_score += grade * 1.5;
        }
        else if (score == "D0")
        {
            total_score += grade * 1.0;
        }
        else if (score == "P")
        {
            continue;
        }
        total_grade += grade;
    }

    std::cout << std::fixed << std::setprecision(6) << total_score / total_grade << "\n";

    return 0;
}