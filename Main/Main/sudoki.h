#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void sudokuTemplate();

int play();

int checkRows(int row);

int checkColumns(int col);

void resetArray(int arr[]);

int checkGrid();

int checkBoxRandom();

void randomise();

int checkResult();

void drawSudoki();