#ifndef GOLLIB_H_INCLUDED
#define GOLLIB_H_INCLUDED
#include <stdbool.h>
void GetSettings(int *xAxis, int *yAxis, char *symbolLife, char *symbolDead, int *percentage, int *mode);
void SetAndPrintRndmCells(int percentage, int yAxis, bool area[][yAxis], int xAxis, char symbolDead, char symbolLife);
void SetIteration(int yAxis, bool tempArea[][yAxis], bool area[][yAxis], int xAxis);
void PrintIteration(int yAxis, bool area[][yAxis], int xAxis, char symbolLife, char symbolDead);
void PrintAutomatically(int yAxis, bool tempArea[][yAxis], bool area[][yAxis], int xAxis, char symbolLife, char symbolDead);
void WriteTempAreaIntoArea(int yAxis, bool tempArea[][yAxis], bool area[][yAxis], int xAxis);
#endif // GOLLIB_H_INCLUDED
