#include <stdio.h>
#include <stdlib.h>
#include "GoLLIB.h"
#include <stdbool.h>
#include <time.h>

void GetSettings(int *xAxis, int *yAxis, char *symbolLife, char *symbolDead, int *percentage, int *mode, int *mSeconds)
{
    printf("Enter symbol for living cells:");
    scanf("%c", symbolLife);
    fflush(stdin);
    printf("Enter symbol for dead cells:");
    scanf("%c", symbolDead);
    printf("Enter x-axis value:");
    scanf("%d", xAxis);
    printf("Enter y-axis value:");
    scanf("%d", yAxis);
    printf("Enter percentage:");
    scanf("%d", percentage);
    printf("1 for automatic mode:");
    scanf("%d", mode);
    if(*mode == 1)
    {
        printf("Seconds between Iterations:");
        scanf("%d", mSeconds);
    }
    system("cls");
}

void SetAndPrintRndmCells(int percentage, int yAxis, bool area[][yAxis], int xAxis, char symbolDead, char symbolLife)
{
    int i;
    int y;
    int rndm;
    srand(time(NULL));
    printf("First Iteration:\n");
    for(i=0; i<yAxis; i++)
    {
        for(y=0; y<xAxis; y++)
        {
            rndm = rand()%100;

            if(rndm <= percentage)
            {
                area[i][y] = true;

            }
            else
            {
                area[i][y] = false;
            }
        }
    }
    PrintIteration(yAxis, area, xAxis, symbolLife, symbolDead);
}


void SetIteration(int yAxis, bool tempArea[][yAxis], bool area[][yAxis], int xAxis)
{
    int counter;
    int i;
    int y;

    for(i=0; i<yAxis; i++)
    {
        for(y=0; y<xAxis; y++)
        {
            counter = 0;

            if(area[i-1][y-1] == true && i-1 >= 0 && y-1 >= 0)
            {
                counter +=1;
            }
            if(area[i-1][y] == true && i-1 >= 0)
            {
                counter +=1;
            }
            if(area[i][y-1] == true && y-1 >= 0)
            {
                counter +=1;
            }
            if(area[i+1][y+1] == true && i+1 <= yAxis-1 && y+1 <= xAxis-1)
            {
                counter +=1;
            }
            if(area[i+1][y] == true && i+1 <= yAxis-1)
            {
                counter +=1;
            }
            if(area[i][y+1] == true && y+1 <= xAxis-1)
            {
                counter +=1;
            }
            if(area[i+1][y-1] == true && y-1 >= 0 && i+1 <= yAxis-1)
            {
                counter +=1;
            }
            if(area[i-1][y+1] == true && i-1 >= 0 && y+1 <= xAxis-1)
            {
                counter +=1;
            }

            if(area[i][y] == true)
            {
                if(counter > 3 || counter < 2)
                {
                    tempArea[i][y] = false;
                }
                else
                {
                    tempArea[i][y] = true;
                }

            }
            else
            {
                if(counter == 3)
                {
                    tempArea[i][y] = true;
                }
                else
                {
                    tempArea[i][y] = false;
                }
            }
        }

    }

}


void PrintIteration(int yAxis, bool area[][yAxis], int xAxis, char symbolLife, char symbolDead)
{
    int i;
    int y;

    for(i=0; i<yAxis; i++)
    {
        for(y=0; y<xAxis; y++)
        {
            if(area[i][y] == true)
            {
                printf("%c", symbolLife);
            }
            else
            {
                printf("%c", symbolDead);
            }
        }
        printf("\n");
    }
}
bool WriteTempAreaIntoArea(int yAxis, bool tempArea[][yAxis], bool area[][yAxis], int xAxis)
{
    int i;
    int y;
    bool arrayEven;
    arrayEven = true;
    for(i=0; i<yAxis; i++)
    {
        for(y=0; y<xAxis; y++)
        {
            if(area[i][y] != tempArea[i][y])
            {
                area[i][y] = tempArea[i][y];
                arrayEven = false;
            }
        }
    }
    return(arrayEven);
}
void PrintAutomatically(int yAxis, bool tempArea[][yAxis], bool area[][yAxis], int xAxis, char symbolLife, char symbolDead, int mSeconds, bool automatic)
{
    int iterationNo;
    double clockBefore;
    double clockAfter;

    clockBefore = clock()/CLOCKS_PER_SEC;
    iterationNo = 2;
    while(1)
    {
        if (automatic){
            //Sleep(mSeconds);
        }
        else
        {
            system("pause");
        }
        system("cls");
        SetIteration(yAxis, tempArea, area, xAxis);
        if (WriteTempAreaIntoArea(yAxis, tempArea, area, xAxis))
        {
            break;
        }
        clockAfter = clock()/CLOCKS_PER_SEC;
        PrintIterationPerSecond(clockBefore, clockAfter, iterationNo);
        PrintIteration(yAxis, area, xAxis, symbolLife, symbolDead);
        iterationNo++;
    }
}


void PrintIterationPerSecond(double startTime, double endTime, int noOfIterations)
{
    double iterationPerSecond;
    double clockDifference;
    clockDifference = endTime - startTime;
    iterationPerSecond = clockDifference/noOfIterations;
    printf("Iterations per second: %f\n", iterationPerSecond);
    printf("Iteration No.: %d\n", noOfIterations);
}
