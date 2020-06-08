#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include <unistd.h>
int main()
{
    int xAxis;
    int yAxis;
    int i;
    int y;
    char symbolLife;
    char symbolDead;
    int rndm;
    int percentage;
    int counter;
    int mode;

    srand(time(NULL));

    printf("Enter symbol for living cells:");
    scanf("%c", &symbolLife);
    fflush(stdin);
    printf("Enter symbol for dead cells:");
    scanf("%c", &symbolDead);
    printf("Enter x-axis value:");
    scanf("%d", &xAxis);
    printf("Enter y-axis value:");
    scanf("%d", &yAxis);
    printf("Enter percentage:");
    scanf("%d", &percentage);
    printf("1 for automatic mode:");
    scanf("%d", &mode);
    system("cls");

    bool area[xAxis][yAxis];
    bool tempArea[xAxis][yAxis];

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



    for(i=0; i<yAxis; i++)
    {
        for(y=0; y<xAxis; y++)
        {
            if(area[i][y] == true)
            {
                printf("%c",symbolLife);
            }
            else
            {
                printf("%c",symbolDead);
            }
        }
        printf("\n");
    }

while(1){
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



    for(i=0; i<yAxis; i++)
    {
        for(y=0; y<xAxis; y++)
        {
            area[i][y] = tempArea[i][y];
        }
    }


    system("cls");

    for(i=0; i<yAxis; i++)
    {
        for(y=0; y<xAxis; y++)
        {
            if(area[i][y] == true)
            {
                printf("%c",symbolLife);
            }
            else
            {
                printf("%c",symbolDead);
            }
        }
        printf("\n");
    }
Sleep(100);
}



    return 0;
}


