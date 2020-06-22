#ifndef GOLLIB_H_INCLUDED
#define GOLLIB_H_INCLUDED
#include <stdbool.h>
void GetSettings(int *xAxis, int *yAxis, char *symbolLife, char *symbolDead, int *percentage, int *mode, int *mSeconds, int *dieTill, int *dieFrom, int *giveBirthAt);
void SetAndPrintRndmCells(int percentage, int yAxis, bool area[][yAxis], int xAxis, char symbolDead, char symbolLife);
void SetIteration(int yAxis, bool tempArea[][yAxis], bool area[][yAxis], int xAxis, int dieTill, int dieFrom, int giveBirthAt);
void PrintIteration(int yAxis, bool area[][yAxis], int xAxis, char symbolLife, char symbolDead);
void PrintCells(int yAxis, bool tempArea[][yAxis], bool area[][yAxis], int xAxis, char symbolLife, char symbolDead, int mSeconds, bool automatic, int dieTill, int dieFrom, int giveBirthAt);
bool WriteTempAreaIntoArea(int yAxis, bool tempArea[][yAxis], bool area[][yAxis], int xAxis);
void PrintIterationPerSecond(double startTime, double endTime, int noOfIterations);
#endif // GOLLIB_H_INCLUDED
