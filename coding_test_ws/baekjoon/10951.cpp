// https://www.acmicpc.net/problem/10951
#include <iostream>
#include <functional>

#define typeppi unsigned

typedef std::function<bool(int)> inputCondition;
typedef std::function<bool(bool)> eofDetector;

typeppi** createArray(unsigned col, unsigned row)
{
    typeppi** arr=(typeppi**)malloc(sizeof(typeppi*)*col);
    for (unsigned i = 0; i < col; i++)
    {
        arr[i]=(typeppi*)malloc(sizeof(typeppi)*row);
    }
    return arr;
}

void deleteArray(typeppi** arr, unsigned row)
{
    for(unsigned i = 0; i < row; i++)
    {
        free(arr[i]);
    }
    free(arr);
}

// https://stackoverflow.com/questions/39208929/resizing-2d-arrays-in-c
typeppi** resizeArray(typeppi** arr, unsigned col, unsigned row, unsigned new_col, unsigned new_row)
{
    row = row;
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

    for(unsigned i=0; i<new_col; i++)
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

typeppi userInputWithCondition(inputCondition ic, eofDetector eof_d)
{
    std::cin.tie(NULL);
    typeppi input1, input2;
    while(std::cin >> input1 >> input2)
    {
        if(!ic(input1)||!ic(input2))
        {
            continue;
        }
        if(eof_d(std::cin.eof()))
        {
            break;
        }
    }
    return input1+input2;
}

typeppi** userInput(unsigned col, unsigned row, inputCondition ic)
{
    unsigned final_col_size=col;
    bool eof_status_receiver = false;
    eofDetector detector = [&eof_status_receiver](bool eof_received){
        if(eof_received && std::cin.rdbuf()->in_avail() == 1)
        {
            eof_status_receiver = true;
        }
        else
        {
            eof_status_receiver = false;
        }
        return eof_received;
    };
    typeppi** results=createArray(col,row);
    unsigned new_col = 3;

    unsigned i = 0;
    while(1)
    {
        final_col_size = new_col;
        results[i][row-1] = userInputWithCondition(ic, detector);

        if(eof_status_receiver)
        {
            break;
        }

        if(i==new_col-1)
        {
            unsigned pre_col = new_col;
            new_col += 3;
            results=resizeArray(results,pre_col,row,new_col,row);
        }
        i++;
    }

    // To detect end of array with 0(default value) in another function
    results=resizeArray(results,final_col_size,row,final_col_size+1,row);
    results[final_col_size][0] = 0;

    return results;
}

int main()
{
    std::ios::sync_with_stdio(false);
    unsigned col = 3;
    unsigned row = 1;

    inputCondition ic;
    ic = [](int input){
        return 0 < input && input < 10;
    };

    unsigned** results = userInput(col, row, ic);

    unsigned n = 0;
    while(1)
    {
        if(results[n][0] == 0)
        {
            break;
        }
        std::cout << results[n][0] << "\n" << std::flush;
        n++;
    }

    deleteArray(results, row);

    return 0;
}