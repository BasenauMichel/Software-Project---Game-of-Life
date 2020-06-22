/*
*Author: Alaeddine Mohamed, Basenau Michel
*Date: 25.05.2020
*
*A program which represents "Conway's Game of Life". It shows an Area which contains rows and columns,
*each cell can have a state either dead or alive.
*In the beginning the program will create a starting generation of random cells which are alive. After
*that the program will create a subsequent generation, where it checks each cell at the same time and
*considers the rules to decide if the cell will die or come alive. Then it repeats creating subsequent
*generations until there no changes to the cells anymore or until the user stops the program.
*
*/

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
    //Declaration of the needed variables
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
    int import;

    //Calling function to get the values for the settings
    GetSettings(&xAxis, &yAxis, &symbolLife, &symbolDead, &percentage, &mode, &mSeconds, &dieTill, &dieFrom, &giveBirthAt,&import);

    mSeconds = mSeconds * 1000;

    //If the user wishes to import from a txt file
    if(import == 1)
    {
        CountRowsAndColumns(&yAxis,&xAxis);
        printf("%d",xAxis);
        printf("%d",yAxis);
    }

    bool area[xAxis][yAxis];
    bool tempArea[xAxis][yAxis];


    if(import != 1)
    {
        //Writing the beginning generation in the console
        SetAndPrintRndmCells(percentage, yAxis, area, xAxis, symbolDead, symbolLife);
    }
    else
    {
        ImportArea(yAxis,xAxis,area);
    }

    //If its on automatic mode
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


