#include "sudoku.h"

using namespace std;
int grid[9][9] = { 0 }, row, col, num;


void sudokuTemplate()
{
    int threeRowCounter = 0;
    for (int i = 0; i < 9; i++)
    {
        threeRowCounter = 0;
        for (int j = 0; j < 9; j++)
        {
            threeRowCounter++;
            if (grid[i][j] == 0)
            {
                cout << "-";
            }
            else
            {
                cout << grid[i][j];
            }
            cout << " ";
            if (threeRowCounter % 3 == 0)
            {
                cout << "  ";
            }
        }
        cout << endl;
        if (i == 2 or i == 5)
        {
            cout << endl;
        }
    }
}


int check_row(int row)
{

    int arr[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    for (int j = 0; j < 9; j++) {
        arr[grid[row][j]]++;
    }
    for (int k = 0; k < 9; k++) {
        if (arr[k] != 1) {
            return 0;
        }
    }
    return 1;
}

int check_col(int col) {
    int arr[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    for (int j = 0; j < 9; j++) {
        arr[grid[j][col]]++;
    }
    for (int k = 1; k < 10; k++) {
        if (arr[k] != 1) {
            return 0;
        }
    }
    return 1;
}

void resetArray(int arr[]) {
    for (int i = 0; i < 9; i++)
    {
        arr[i] = 0;
    }
}

int checkBox() {
    int arr[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, counterRow = 3, counterCol = 3, valueRow = 0, valueCol = 0;
    while (valueRow <= 6)
    {
        for (int i = valueRow; i < counterRow; i++) {
            for (int j = 0; j < counterCol; j++) {
                arr[grid[i][j]]++;
            }
        }
        for (int k = 1; k < 10; k++) {
            if (arr[k] != 1) {
                return 0;
            }
        }
        counterCol += 3;

        if (counterCol == 9)
        {
            counterRow += 3;
            counterCol = 0;
            valueRow += 3;
        }

        resetArray(arr);
    }
    return 1;
}
int check_box_random() {
    int arr[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, counterRow = 3, counterCol = 3, valueRow = 0, valueCol = 0;
    while (valueRow <= 6)
    {
        for (int i = valueRow; i < counterRow; i++) {
            for (int j = 0; j < counterCol; j++) {
                arr[grid[i][j]]++;
            }
        }
        for (int k = 1; k < 10; k++) {
            if (arr[k] > 1) {
                return 0;
            }
        }
        counterCol += 3;

        if (counterCol == 9)
        {
            counterRow += 3;
            counterCol = 0;
            valueRow += 3;
        }

        resetArray(arr);
    }
    return 1;
}

void fill_random()
{
    
    srand(time(0));

    int ran = (rand() % 20) + 5;
    for (int i = 1; i < ran; i++)
    {
        int digit = rand() % 10;
        int r = rand() % 10, c = rand() % 10;

        if (grid[r][c] != digit)
        {
            int count = 0;
            grid[r][c] = digit;
            for (int i = 0; i < 9; i++) {
                if (grid[r][i] == digit) {
                    count++;
                }
            }
            if (count > 1) {
                grid[r][c] = 0;
            }
            count = 0;
            for (int i = 0; i < 9; i++) {
                if (grid[i][c] == digit) {
                    count++;
                }
            }
            if (count > 1) {
                grid[r][c] = 0;
            }
            if (check_box_random() == 0) {
                grid[r][c] = 0;
            }
        }
        else {
            
            continue;
        }
    }
}
int checkResult() {
    for (int i = 0; i < 9; i++) {
        if (check_row(i) == 0) {
            return 0;
        }
    }
    for (int i = 0; i < 9; i++) {
        if (check_col(i) == 0) {
            return 0;
        }
    }
    if (checkBox() == 0) {
        return 0;
    }
    return 1;
}
