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
    int dieTill;
    int dieFrom;
    int giveBirthAt;

    GetSettings(&xAxis, &yAxis, &symbolLife, &symbolDead, &percentage, &mode, &mSeconds, &dieTill, &dieFrom, &giveBirthAt);
    mSeconds = mSeconds * 1000;

    bool tempArea[xAxis][yAxis];
    bool area[xAxis][yAxis];
    SetAndPrintRndmCells(percentage, yAxis, area, xAxis, symbolDead, symbolLife);

    if (mode == 1)
    {
        PrintCells(yAxis, tempArea, area, xAxis, symbolLife, symbolDead, mSeconds, true, dieTill, dieFrom, giveBirthAt);
    }
    else
    {
     PrintCells(yAxis, tempArea, area, xAxis, symbolLife, symbolDead, 0, false, dieTill, dieFrom, giveBirthAt);
    }
    return 0;
}


