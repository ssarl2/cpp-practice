// https://www.acmicpc.net/problem/10952
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

void deleteArray(typeppi** arr, unsigned row)
{
    for(unsigned i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

// https://stackoverflow.com/questions/39208929/resizing-2d-arrays-in-c
typeppi** resizeArray(typeppi** arr, unsigned col, unsigned row, unsigned new_col, unsigned new_row)
{
    if(col > new_col)
    {
        for(unsigned i = new_col; i < col; i++)
        {
            free(arr[i]);
        }
        return arr;
    }

    arr = (typeppi**)realloc(arr,sizeof(typeppi*)*new_col);
    if(arr == NULL)
    {
        return NULL;
    }

    for(unsigned i = 0; i<new_col; i++)
    {
        if(col>i)
        {
            arr[i] = (typeppi*)realloc(arr[i], sizeof(typeppi)*new_row);
        }
        else
        {
            arr[i] = (typeppi*)malloc(sizeof(typeppi)*new_row);
        }

        if(arr[i] == NULL)
        {
            for(unsigned j=0; j<i; j++)
            {
                free(arr[j]);
            }
            free(arr);

            return NULL;
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
    typeppi** inputs=createArray(1,row_input_size);
    if(col_input_size == 0)
    {
        unsigned new_col = 3;
        inputs=resizeArray(inputs,1,row_input_size,new_col,row_input_size);

        unsigned i = 0;
        while(1)
        {
            for(size_t j=0; j<row_input_size; j++)
            {
                inputs[i][j] = userInputWithCondition(cc[0]);
            }

            if(inputs[i][0] == 0 && inputs[i][1] == 0)
            {
                break;
            }

            if(i==new_col-1)
            {
                new_col += 3;
                inputs=resizeArray(inputs,new_col-3,row_input_size,new_col,row_input_size);
            }
            i++;
        }
    }
    else
    {
        inputs=resizeArray(inputs,1,row_input_size,col_input_size,row_input_size);

        for(size_t i=0; i<col_input_size; i++)
        {
            for(size_t j=0; j<row_input_size; j++)
            {
                inputs[i][j] = userInputWithCondition(cc[0]);
            }
        }
    }

    return inputs;
}

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    unsigned user_input_size = 0;
    unsigned row_input_size = 2;

    callbackCondition cc[1];
    cc[0] = [](int input){
        return 0 <= input && input <= 100;
    };

    unsigned** results = userInput(user_input_size, cc, row_input_size);

    unsigned n=0;
    while(1)
    {
        if(results[n][0]==0 && results[n][1]==0)
        {
            break;
        }
        std::cout << results[n][0] + results[n][1] << "\n";
        n++;
    }

    deleteArray(results, row_input_size);

    return 0;
}