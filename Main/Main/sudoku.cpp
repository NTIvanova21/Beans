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



