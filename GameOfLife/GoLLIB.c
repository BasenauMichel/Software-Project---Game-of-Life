#include <stdio.h>
#include "GoLLIB.h"
#include <stdbool.h>

void GetSettings(int *xAxis, int *yAxis, char *symbolLife, char *symbolDead, int *percentage, int *mode)
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
    system("cls");
}

void SetAndPrintRndmCells(bool **area, int percentage, int yAxis, int xAxis, char symbolDead, char symbolLife)
{
    int i;
    int y;
    int rndm;
    srand(time(NULL));

    for(i=0; i<yAxis; i++)
    {
        for(y=0; y<xAxis; y++)
        {
            rndm = rand()%100;

            if(rndm <= percentage)
            {
                area[i][y] = true;
                printf("%c", symbolLife);

            }
            else
            {
                area[i][y] = false;
                printf("%c",symbolDead);
            }
        }
        printf("\n");
    }
}


void SetIteration(bool **tempArea, bool **area, int yAxis, int xAxis)
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


void PrintIteration(bool **area, int yAxis, int xAxis, char symbolLife, char symbolDead)
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
void WriteTempAreaIntoArea(bool **tempArea, bool **area, int yAxis, int xAxis)
{
    int i;
    int y;
        for(i=0; i<yAxis; i++)
    {
        for(y=0; y<xAxis; y++)
        {
            area[i][y] = tempArea[i][y];
        }
    }
}
void PrintAutomatically(bool **tempArea, bool **area, int yAxis, int xAxis, char symbolLife, char symbolDead)
{
    while(1)
    {
     SetIteration(tempArea, area, yAxis, xAxis);
     WriteTempAreaIntoArea(tempArea, area, yAxis, xAxis);
     PrintIteration(area, yAxis, xAxis, symbolLife, symbolDead);
     system("cls");
    }
}
