#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void sudokuTemplate();

int check_row(int row);

int check_col(int col);

void resetArray(int arr[]);

int checkBox();

int check_box_random();

void fill_random();

int checkResult();
