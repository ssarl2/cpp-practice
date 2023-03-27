// https://www.acmicpc.net/problem/11022
#include <iostream>
#include <functional>

#define typeppi unsigned

typedef std::function<bool(int)> callbackCondition;

typeppi** createArray(unsigned col, unsigned row)
{
    typeppi** arr=(typeppi**)malloc(sizeof(typeppi*)*col);
    for (unsigned i = 0; i < col; i++)
    {
        arr[i]=(typeppi*)malloc(sizeof(typeppi)*row);
        for (unsigned j = 0; j < row; j++)
        {
            arr[i][j]=0;
        }
    }
    return arr;
}

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

typeppi** userInput(unsigned col_input_size, callbackCondition cc[], unsigned row_input_size)
{
    typeppi** inputs=createArray(col_input_size,row_input_size);

    for(size_t i=0; i<col_input_size; i++)
    {
        for(size_t j=0; j<row_input_size; j++)
        {
            inputs[i][j] = userInputWithCondition(cc[0]);
        }
    }

    return inputs;
}

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    const unsigned test_cases_size = 1;
    const unsigned row_input_size = 2;

    callbackCondition cc[1];
    cc[0] = [](int input){
        return input > 0;
    };

    unsigned test_cases = userInput(test_cases_size, cc, 1)[0][0];

    callbackCondition test_cases_cc[test_cases];
    test_cases_cc[0] = [](int input){
        return input > 0 && input < 10;
    };

    typeppi** results = userInput(test_cases, test_cases_cc, row_input_size);

    for (size_t i = 0; i < test_cases; i++)
    {
        std::cout << "Case #"<<i+1<< ": " << results[i][0] << " + " << results[i][1] << " = " << results[i][0] + results[i][1] << "\n";
    }

    for(unsigned i = 0; i < row_input_size; i++)
    {
        delete[] results[i];
    }
    delete[] results;

    return 0;
}