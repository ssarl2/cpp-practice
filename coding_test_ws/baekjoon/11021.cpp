// https://www.acmicpc.net/problem/11021
#include <iostream>
#include <functional>

#define typeppi unsigned

typedef std::function<bool(int)> callbackCondition;

typeppi userInputWithCondition(callbackCondition cc)
{
    std::cin.tie(NULL);

    typeppi input;
    std::cin >> input;
    while(!cc(input))
    {
        std::cin >> input;
    }
    return input;
}

typeppi* userInput(size_t col_input_size, callbackCondition cc[], size_t row_input_size)
{
    typeppi* inputs = new typeppi[col_input_size];

    if(col_input_size == 1)
    {
        inputs[0] = userInputWithCondition(cc[0]);
    }
    else
    {
        for(size_t i=0; i<col_input_size; i++)
        {
            for(size_t j = 0; j < row_input_size; j++)
            {
                inputs[i] += userInputWithCondition(cc[0]);
            }
        }
    }

    return inputs;
}

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    unsigned test_cases_size = 1;
    unsigned row_input_size = 2;

    callbackCondition cc[1];
    cc[0] = [](int input){
        return input > 0;
    };

    unsigned test_cases = userInput(test_cases_size, cc, 1)[0];

    callbackCondition test_cases_cc[test_cases];
    test_cases_cc[0] = [](int input){
        return input > 0 && input < 10;
    };

    typeppi* results = userInput(test_cases, test_cases_cc, row_input_size);

    for (size_t i = 0; i < test_cases; i++)
    {
        std::cout << "Case #"<<i+1<< ": " << results[i] << "\n";
    }

    return 0;
}