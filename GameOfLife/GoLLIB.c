#include <stdio.h>
#include <stdlib.h>
#include "GoLLIB.h"
#include <stdbool.h>
#include <time.h>

void GetSettings(int *xAxis, int *yAxis, char *symbolLife, char *symbolDead, int *percentage, int *mode, int *mSeconds, int *dieTill, int *dieFrom, int *giveBirthAt,int *import)
{
    //Input of the settings
    int changeRule;
    printf("Enter symbol for living cells:");
    scanf("%c", symbolLife);
    fflush(stdin);
    printf("Enter symbol for dead cells:");
    scanf("%c", symbolDead);
    printf("1 if you wish to import from a .txt file?");
    scanf("%d",&import);
    if(import != 1)
    {
        printf("Enter x-axis value:");
        scanf("%d", xAxis);
        printf("Enter y-axis value:");
        scanf("%d", yAxis);
        printf("Enter percentage:");
        scanf("%d", percentage);
    }

    printf("1 for automatic mode:");
    scanf("%d", mode);

    if(*mode == 1)
    {
        printf("Seconds between Iterations:");
        scanf("%d", mSeconds);
    }
    printf("1 to Change Rules:");
    scanf("%d", &changeRule);
    if (changeRule == 1)
    {
        printf("Cells die, if number of neighbors more than:");
        scanf("%d", dieFrom);
        printf("Cells die, if number of neighbors less than:");
        scanf("%d", dieTill);
        printf("New cells are born if number of living neighbors is:");
        scanf("%d", giveBirthAt);
    }
    else
    {
        *dieFrom = 2;
        *dieTill = 3;
        *giveBirthAt = 3;
    }
    system("cls");
}

void SetAndPrintRndmCells(int percentage, int yAxis, bool area[][yAxis], int xAxis, char symbolDead, char symbolLife)
{
    //Sets the random values
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
    //Call function to print the area
    PrintIteration(yAxis, area, xAxis, symbolLife, symbolDead);
}


void SetIteration(int yAxis, bool tempArea[][yAxis], bool area[][yAxis], int xAxis, int dieTill, int dieFrom, int giveBirthAt)
{
    int counter;
    int i;
    int y;

    //Counts numbers of neighboured living cells
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

            //Applys the rules
            if(area[i][y] == true)
            {
                if(counter > dieTill || counter < dieFrom)
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
                if(counter == giveBirthAt)
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
    //Prints the iteration
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

    //Reads each value from the temporary array and writes it in the area
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
void PrintCells(int yAxis, bool tempArea[][yAxis], bool area[][yAxis], int xAxis, char symbolLife, char symbolDead, int mSeconds, bool automatic, int dieTill, int dieFrom, int giveBirthAt)
{
    int iterationNo;
    double clockBefore;
    double clockAfter;
    int exportfile;

    clockBefore = clock()/CLOCKS_PER_SEC;
    iterationNo = 2;

    while(1)
    {
        if (automatic)
        {
            //Sleep(mSeconds);
        }
        else
        {
            printf("Press 1 to export current state of cells to .txt file: ");
            scanf("%d", &exportfile);
            system("pause");
            if(exportfile == 1)
            {
                ExportCurrentState(yAxis, xAxis, area, symbolLife, symbolDead);
            }
        }
        SetIteration(yAxis, tempArea, area, xAxis, dieTill, dieFrom, giveBirthAt);
        if (WriteTempAreaIntoArea(yAxis, tempArea, area, xAxis))
        {
            break;
        }
        system("cls");
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


void ExportCurrentState(int yAxis,int xAxis,bool area[][yAxis],char symbolLife, char symbolDead)
{
    int i = 0;
    int y = 0;


    FILE * fPtr;
    fPtr = fopen("saved/area.txt","w");

    if(fPtr == NULL)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }

    for(i=0; i<yAxis; i++)
    {
        for(y=0; y<xAxis; y++)
        {
            if(area[i][y] == true)
            {
                fputs("1", fPtr);

            }
            else
            {
                fputs("0", fPtr);
            }
        }

        fputs("\n", fPtr);
    }

    fclose(fPtr);

}

void CountRowsAndColumns(int *yAxis, int *xAxis)
{
    yAxis = 0;
    xAxis = 0;
    int cols;
    FILE *file = fopen("saved/area.txt", "r");
    char c;

    do
    {
        c = fgetc(file);
        if(c == '\n')
        {
            yAxis++;
            xAxis = cols;
            cols= 0;
        }
        else
        {
            cols ++;
        }
    }
    while (c != EOF);

    fclose(file);
}

void ImportArea(int yAxis,int xAxis,bool area[][yAxis])
{
    int i,y;
    char ch;
    FILE *file = fopen("saved/area.txt", "r");
    size_t n = 0;
    char c;
    if (file == NULL)
    {
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    fseek(file, 0, SEEK_SET);

    while ((c = fgetc(file)) != EOF)
    {
        for(i=0; i<yAxis; i++)
        {
            for(y=0; y<xAxis; y++)
            {
                if(c == "1")
                {
                    area[i][y]= true;
                }
                else
                {
                    area[i][y]= false;
                }
            }
        }
    }

    fclose(file);
}
