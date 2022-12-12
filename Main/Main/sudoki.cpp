#include "sudoki.h"

int grid[9][9] = { 0 }, row, col, input;

int missing = 81;

//Create the sudoku Template
void sudokuTemplate()
{
    //Initiate a counter which counts each third row
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

//Allow the player to input numbers 
bool play() {
    cout << endl << "Enter row number: ";
    cin >> row;

    cout << endl << "Enter column number: ";
    cin >> col;

    cout << endl << "Enter number: ";
    cin >> input;

    //Check if the inputed number contains a number from 1 to 9
    if (input >= 1 and input <= 9)
    {
        //Check if the inputed row contains a number from 1 to 9
        if (row >= 1 and row <= 9)
        {
            //Check if the inputed column contains a number from 1 to 9
            if (col >= 1 and col <= 9)
            {
                row--;
                col--;

                //Check if the number is repeated in either the same column, row or grid
                return canPlaceNumber(row, col, input);
            }
        }
    }

    return 0;
}

//Check whether you can place the inputed number into the wanted place
bool canPlaceNumber(int row, int col, int num) {

    //Check if the desired number has not already been entered
    if (grid[row][col] != 0 && grid[row][col] != num) {
        return false;
    }

    //Check if number is equal to 0
    if (grid[row][col] != 0) {
        return false;
    }

    //Check if the number already exists in the same row
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == num) {
            return false;
        }
    }

    //Check if the number already exists in the same column
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == num) {
            return false;
        }
    }

    int rowStart = (row / 3) * 3;
    int colStart = (col / 3) * 3;

    //Check if number already exists in the same grid
    for (int i = rowStart; i < rowStart + 3; i++) {
        for (int j = colStart; j < colStart + 3; j++) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

//Randomise numbers in the begining of the game
void randomise()
{
    //Generate a new seed each time the code is ran
    srand(time(0));

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            //Randomise a number from 1 through 9
            int num = rand() % 9 + 1;

            //Check if that number can be placed at the desired place
            if (canPlaceNumber(i, j, num))
                grid[i][j] = num;
        }
    }
}

void drawSudoki()
{
    //Randomise the sudoku template
    randomise();

    while (1) {
        system("cls");

        //Check if the player has finished filling up the sudoku
        if (missing == 0) {
            sudokuTemplate();
            cout << endl << "Congratulations!\n";
            break;
        }

        sudokuTemplate();

        //Enter number in sudoku template
        if (play() == 1)
        {
            grid[row][col] = input;
            missing--;
        }
    }
}