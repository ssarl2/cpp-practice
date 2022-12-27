// https://adventofcode.com/2018/day/5

#include <iostream>
#include <vector>
#include <tools.h>

tools::debug_level debug_mode = tools::normal;

class Solution
{
public:
    Solution()
    {}
    std::string logic(std::string input)
    {
        int previous_input_size = 0;
        int input_size = input.size();

        while(true)
        {
            if(previous_input_size == input_size)
            {
                break;
            }

            previous_input_size = input.size();
            std::string str_res = "";
            std::vector<std::string> vec_str = divideStrMultiply(input);

            for (auto str : vec_str)
            {
                if(str.size() == 1)
                {
                    if(reactChars(str_res.back(), str.at(0)) == "")
                    {
                        str_res.pop_back();
                    }
                    else
                    {
                        str_res += str;
                    }
                }
                else if(str.size() == 2)
                {
                    if(reactChars(str_res.back(), str.front()) == "")
                    {
                        str_res.pop_back();
                        str_res.push_back(str.back());
                    }
                    else
                    {
                        str_res += reactChars(str.front(), str.back());
                    }
                }
                else
                {
                    tools::log(tools::debug_level::error, "Error: Wrong string size was received.");
                    exit(1);
                }
            }
            input = str_res;
            input_size = input.size();
        }

        return input;
    }
    int solvePartOne(std::string input)
    {
        return logic(input).size();
    }
    int solvePartTwo(std::string input)
    {
        int min_size = input.size();
        for (char c = 'a'; c <= 'z'; c++)
        {
            std::string rectified_str = removeUperAndLowerChars(input, c);
            std::string output = logic(rectified_str);
            if(min_size > output.size())
            {
                min_size = output.size();
            }
            tools::log(debug_mode, "Processing.. (" + std::to_string(c-(int)'a') + "/" + std::to_string((int)'z'-(int)'a')+")");
        }
        return min_size;
    }
private:
    std::string reactChars(char c1, char c2)
    {
        int letter_gap = (int)'a'-(int)'A';
        int reaction = (int)c1 - (int)c2;
        if(std::abs(reaction) == letter_gap)
        {
            return "";
        }
        else
        {
            std::string s{c1, c2};
            return s;
        }
    }
    std::vector<std::string> divideStrMultiply(std::string str)
    {
        std::vector<std::string> vec_str{};
        int len = str.size();
        if(len <= 2)
        {
            vec_str.push_back(str);
        }
        else
        {
            std::string str1 = str.substr(0, len/2);
            std::string str2 = str.substr(len/2);
            std::vector<std::string> vec_returned1 = divideStrMultiply(str1);
            std::vector<std::string> vec_returned2 = divideStrMultiply(str2);
            vec_str.insert(vec_str.end(), vec_returned1.begin(), vec_returned1.end());
            vec_str.insert(vec_str.end(), vec_returned2.begin(), vec_returned2.end());
        }
        return vec_str;
    }
    std::string removeUperAndLowerChars(std::string str, char c)
    {
        str.erase(std::remove(str.begin(), str.end(), c), str.end());
        str.erase(std::remove(str.begin(), str.end(), c-32), str.end());
        return str;
    }

    std::string input_;
};

int main(int argc, char *argv[])
{
    std::vector<std::string> vec_str = tools::readFileAsVecStr(argv[1]);

    std::string input = vec_str.at(0);
    Solution s;

    int part_one_answer_ = s.solvePartOne(input);
    int part_two_answer_ = s.solvePartTwo(input);


    tools::log(debug_mode, "part one answer : " + std::to_string(part_one_answer_));
    tools::log(debug_mode, "part two answer : " + std::to_string(part_two_answer_));

    return 0;
}