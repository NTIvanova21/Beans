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

int play() {
    cout << endl;
    cin >> row >> col >> num;
    row--;
    col--;
    if (num >= 0 and num <= 9) {
        return 1;
    }
    else {
        return 0;
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

