#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int main()
{
    int xAxis;
    int yAxis;
    int i;
    int y;
    char symbol;
    int rndm;
    int percentage;

    srand(time(NULL));

    printf("Enter symbol:");
    scanf("%c", &symbol);
    printf("Enter x-axis value:");
    scanf("%d", &xAxis);
    printf("Enter y-axis value:");
    scanf("%d", &yAxis);
    printf("Enter percentage:");
    scanf("%d", &percentage);
    system("cls");

    bool area[xAxis][yAxis];

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


while(1){
    for(i=0; i<yAxis; i++)
    {
        for(y=0; y<xAxis; y++)
        {
            if(area[i][y] == true)
            {
                printf("%c",symbol);
            }
            else
            {
                printf(" ");
            }

        }
        printf("\n");

    }
}

//temparray




    return 0;
}


