#ifndef GOLLIB_H_INCLUDED
#define GOLLIB_H_INCLUDED
#include <stdbool.h>
//Reads the settings from the user input
void GetSettings(int *xAxis, int *yAxis, char *symbolLife, char *symbolDead, int *percentage, int *mode, int *mSeconds, int *dieTill, int *dieFrom, int *giveBirthAt, int *import);
//Sets the randoms values for an area and prints the cells of the first generation
void SetAndPrintRndmCells(int percentage, int yAxis, bool area[][yAxis], int xAxis, char symbolDead, char symbolLife);
//Reads every cell, counts the neighboured cells and applys the rules for each cell
void SetIteration(int yAxis, bool tempArea[][yAxis], bool area[][yAxis], int xAxis, int dieTill, int dieFrom, int giveBirthAt);
//Prints out the current state of the cells
void PrintIteration(int yAxis, bool area[][yAxis], int xAxis, char symbolLife, char symbolDead);
//Loop for creating subsequent generations
void PrintCells(int yAxis, bool tempArea[][yAxis], bool area[][yAxis], int xAxis, char symbolLife, char symbolDead, int mSeconds, bool automatic, int dieTill, int dieFrom, int giveBirthAt);
//Writes the values into the array from the temporary array
bool WriteTempAreaIntoArea(int yAxis, bool tempArea[][yAxis], bool area[][yAxis], int xAxis);
//Write the seconds which it need for every iteration
void PrintIterationPerSecond(double startTime, double endTime, int noOfIterations);
//Exports current state of the area into a txt file
void ExportCurrentState(int yAxis, int xAxis, bool area[][yAxis],char symbolLife, char symbolDead);
//Counts the amount of rows and coloums in the txt file
void CountRowsAndColumns(int *yAxis, int *xAxis);
//Import an area from a txt file
void ImportArea(int yAxis,int xAxis ,bool area[][yAxis]);
#endif // GOLLIB_H_INCLUDED
