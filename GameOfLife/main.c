#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <unistd.h>
#include "GoLLIB.h"
#include <time.h>
int main()
{
    int xAxis;
    int yAxis;
    char symbolLife;
    char symbolDead;
    int percentage;
    int mode;
    int mSeconds;
    int neighbour;

    GetSettings(&xAxis, &yAxis, &symbolLife, &symbolDead, &percentage, &mode, &mSeconds);
    mSeconds = mSeconds * 1000;

    bool tempArea[xAxis][yAxis];
    bool area[xAxis][yAxis];
    SetAndPrintRndmCells(percentage, yAxis, area, xAxis, symbolDead, symbolLife);

    if (mode == 1)
    {
        PrintAutomatically(yAxis, tempArea, area, xAxis, symbolLife, symbolDead, mSeconds);
    }
    else
    {
     PrintManually(yAxis, tempArea, area, xAxis, symbolLife, symbolDead);
    }
    return 0;
}


