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

    GetSettings(&xAxis, &yAxis, &symbolLife, &symbolDead, &percentage, &mode);

    bool tempArea[xAxis][yAxis];
    bool area[xAxis][yAxis];
    SetAndPrintRndmCells(area, percentage, yAxis, xAxis, symbolDead, symbolLife);

    /*if (mode == 1)
    {
        PrintAutomatically(tempArea, area, yAxis, xAxis, symbolLife, symbolDead);
    }
*/




    return 0;
}


