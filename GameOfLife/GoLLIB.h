#ifndef GOLLIB_H_INCLUDED
#define GOLLIB_H_INCLUDED
#include <stdbool.h>
void GetSettings(int *xAxis, int *yAxis, char *symbolLife, char *symbolDead, int *percentage, int *mode);
void SetAndPrintRndmCells(bool **area, int percentage, int yAxis, int xAxis, char symbolDead, char symbolLife);
void SetIteration(bool **tempArea, bool **area, int yAxis, int xAxis);
void PrintIteration(bool **area, int yAxis, int xAxis, char symbolLife, char symbolDead);
void PrintAutomatically(bool **tempArea, bool **area, int yAxis, int xAxis, char symbolLife, char symbolDead);
void WriteTempAreaIntoArea(bool **tempArea, bool **area, int yAxis, int xAxis);
#endif // GOLLIB_H_INCLUDED
