// https://www.acmicpc.net/problem/2439
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

void deleteArray(typeppi** arr, unsigned row)
{
    for(unsigned i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    const unsigned user_input_size = 1;
    const unsigned row_input_size = 1;

    callbackCondition cc[1];
    cc[0] = [](int input){
        return 0 <= input && input <= 100;
    };

    unsigned** user_input = userInput(user_input_size, cc, row_input_size);

    for(unsigned i = 0; i < user_input[0][0]; i++)
    {
        for(unsigned j = user_input[0][0]; j > 0; j--)
        {
            if(j<=i+1)
            {
                std::cout << "*";
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }

    deleteArray(user_input, row_input_size);

    return 0;
}