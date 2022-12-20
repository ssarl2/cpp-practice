// https://adventofcode.com/2018/day/5

#include <iostream>
#include <vector>
#include <tools.h>

tools::debug_level debug_mode = tools::normal;

class Input
{
public:
    Input(std::string input)
    : input_(input)
    {}
    std::string getInput()
    {
        return input_;
    }
    void solveQuestionOne()
    {
        std::string input = input_;

        int previous_input_size = 0;
        int input_size = input.size();

        direction d = front;
        while(true)
        {
            if(previous_input_size == input_size)
            {
                if(d == back)
                {
                    break;
                }
                d = back;
            }
            else
            {
                d = front;
            }
            previous_input_size = input.size();
            std::string str_res = "";
            std::vector<std::string> vec_str = divideStrMultiply(input, d);

            for(auto str : vec_str)
            {
                if(str.size() == 1)
                {
                    str_res += str;
                }
                else if(str.size() == 2)
                {
                    str_res += compositeChars((char)str.at(0), (char)str.at(1));
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

        input_ = input;
    }
private:
    enum direction { front, back };
    std::string compositeChars(char c1, char c2)
    {
        int letter_gap = (int)'a'-(int)'A';
        int composition = (int)c1 - (int)c2;
        if(std::abs(composition) == letter_gap)
        {
            return "";
        }
        else
        {
            std::string s{c1, c2};
            return s;
        }
    }
    std::vector<std::string> divideStrMultiply(std::string str, direction d)
    {
        int len = str.size();
        std::string str_front = "";
        std::string str_back = "";
        std::vector<std::string> vec_str{};

        if(len%2 == 1)
        {
            if(d == front)
            {
                int pos = 0;
                str_front = str.at(pos);
                str.erase(pos, 1);
                vec_str.push_back(str_front);
                std::vector<std::string> vs = divideTwoStrMultiply(str);
                vec_str.insert(vec_str.end(), vs.begin(), vs.end());
            }
            else if(d == back)
            {
                int pos = str.size()-1;
                str_back = str.at(pos);
                str.erase(pos, 1);
                std::vector<std::string> vs = divideTwoStrMultiply(str);
                vec_str.insert(vec_str.end(), vs.begin(), vs.end());
                vec_str.push_back(str_back);
            }
        }
        else if(len == 2)
        {
            vec_str.push_back(str);
        }
        else
        {
            std::string str1 = str.substr(0, len/2);
            std::string str2 = str.substr(len/2);
            std::vector<std::string> vec_returned1 = divideStrMultiply(str1, d);
            std::vector<std::string> vec_returned2 = divideStrMultiply(str2, d);
            vec_str.insert(vec_str.end(), vec_returned1.begin(), vec_returned1.end());
            vec_str.insert(vec_str.end(), vec_returned2.begin(), vec_returned2.end());

        }
        return vec_str;
    }
    std::string combineMultipleStr(std::vector<std::string> vec_str)
    {
        std::string str_res = "";
        for(auto str : vec_str)
        {
            str_res += str;
        }
        return str_res;
    }
    std::vector<std::string> divideTwoStrMultiply(std::string str)
    {
        std::vector<std::string> vs{};
        for (size_t i = 0; i < str.size()/2; i++)
        {
            int index = i*2;
            std::string s{str.at(index), str.at(index+1)};
            vs.push_back(s);
        }
        return vs;
    }

    std::string input_;
};

int main(int argc, char *argv[])
{
    std::vector<std::string> input = tools::readFileAsVecStr(argv[1]);

    Input in(input.at(0));

    in.solveQuestionOne();
    tools::log(debug_mode, "str_res : " + in.getInput());
    tools::log(debug_mode, "input size : " + std::to_string(input.at(0).size()));
    tools::log(debug_mode, "str_res size : " + std::to_string(in.getInput().size()));

    return 0;
}