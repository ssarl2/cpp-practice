#include "MazeSolver.h"

int Solve(MazeInfo *Maze)
{
    int i = 0;
    int j = 0;
    int StartFound = FAIL;
    int Result = FAIL;

    Position Start;

    for (i = 0; i < Maze->RowSize; i++)
    {
        for (j = 0; j < Maze->ColumnSize; j++)
        {
            if (Maze->Data[i][j] == START)
            {
                Start.X = j;
                Start.Y = i;
                StartFound = SUCCEED;
                break;
            }
        }

        if (StartFound == SUCCEED)
            break;
    }

    if (StartFound == FAIL)
        return FAIL;

    Result = MoveTo(Maze, &Start);

    Maze->Data[Start.Y][Start.X] = START;

    return Result;
}

int MoveTo(MazeInfo *Maze, Position *Current)
{
    int i = 0;
    int Dirs[] = {NORTH, SOUTH, EASH, WEST};

    Position Next;

    if (Maze->Data[Current->Y][Current->X] == GOAL)
        return SUCCEED;

    Maze->Data[Current->Y][Current->X] = MARKED;

    for (i = 0; i < 4; i++)
    {
        if (GetNextStep(Maze, Current, Dirs[i], &Next) == FAIL)
            continue;

        if (MoveTo(Maze, &Next) == SUCCEED)
            return SUCCEED;
    }

    Maze->Data[Current->Y][Current->X] = WAY;

    return FAIL;
}

int GetNextStep(MazeInfo *Maze, Position *Current, int Direction, Position *Next)
{
    int x = 0, y = 0;
    switch (Direction)
    {
    case NORTH:
        Next->X = Current->X;
        Next->Y = Current->Y - 1;
        y -= 1;

        if (Next->Y == -1)
            return FAIL;

        break;
    case SOUTH:
        Next->X = Current->X;
        Next->Y = Current->Y + 1;
        y += 1;

        if (Next->Y == Maze->RowSize)
            return FAIL;

        break;
    case EASH:
        Next->X = Current->X + 1;
        Next->Y = Current->Y;
        x += 1;

        if (Next->X == Maze->ColumnSize)
            return FAIL;

        break;
    case WEST:
        Next->X = Current->X - 1;
        Next->Y = Current->Y;
        x -= 1;

        if (Next->X == -1)
            return FAIL;

        break;
    }

    if (Maze->Data[Next->Y][Next->X] == WALL)
        return FAIL;
    if (Maze->Data[Next->Y][Next->X] == MARKED)
        return FAIL;

    return SUCCEED;
}

int GetMaze(char *FilePath, MazeInfo *Maze)
{
    int i = 0;
    int j = 0;
    int RowSize = 0;
    int ColumnSize = INIT_VALUE;

    FILE *fp;
    char buffer[MAX_BUFFER];

    if ((fp = fopen(FilePath, "r")) == NULL)
    {
        printf("Cannot open file:%s\n", FilePath);
        return FAIL;
    }

    while (fgets(buffer, MAX_BUFFER, fp) != NULL)
    {
        RowSize++;

        if (ColumnSize == INIT_VALUE)
        {
            ColumnSize = strlen(buffer) - 1;
        }
        else if (ColumnSize != strlen(buffer) - 1)
        {
            printf("Maze data in file:%s is not valid.\n", FilePath);
            fclose(fp);
            return FAIL;
        }
    }

    Maze->RowSize = RowSize;
    Maze->ColumnSize = ColumnSize;
    Maze->Data = (char **)malloc(sizeof(char *) * RowSize);

    for (i = 0; i < RowSize; i++)
        Maze->Data[i] = (char *)malloc(sizeof(char) * ColumnSize);

    rewind(fp);

    for (i = 0; i < RowSize; i++)
    {
        fgets(buffer, MAX_BUFFER, fp);

        for (j = 0; j < ColumnSize; j++)
            Maze->Data[i][j] = buffer[j];
    }

    fclose(fp);
    return SUCCEED;
}