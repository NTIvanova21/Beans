#include "sudoki.h"

int grid[9][9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, row, col, num;

//Create the sudoku template

void sudokuTemplate()
{
    //Initiate a counter for every third column

    int threeColCounter = 0;

    for (int i = 0; i < 9; i++)
    {

        for (int j = 0; j < 9; j++)
        {
            threeColCounter++;

            
            if (grid[i][j] == 0)
            {
                cout << "-";
            }
            else
            {
                cout << grid[i][j];
            }

            cout << " ";

            if (threeColCounter % 3 == 0)
            {
                cout << "  ";
            }
        }

        cout << endl;

        //once you've finished the third and 6th row you seperate them with a line

        if (i == 2 or i == 5)
        {
            cout << endl;
        }
    }
}

//Add the ability to insert numbers while giving clear instrunctions

int play() 
{
    cout << endl << "Enter row number: ";

    cin >> row;

    cout << endl << "Enter column number: ";

    cin >> col;

    cout << endl << "Enter number: ";

    cin >> num;

    //Decrease the numbers entered by 1 so it can be converted to an index number

    row--;
    col--;

    //Check if the number entered is a valid sudoku number
    if (num >= 0 and num <= 9) 
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

//Check if each three by three grid has any repeating numbers

int checkGrid() 
{
    int arr[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 }, temp;
    
    for (int i = 0; i < 9; i++) 
    {
        for (int j = 0; j < 9; j++) 
        {
            arr[i] = grid[i][j];
        }
    }

    //Make a bubble sort algorithm to check for repeating numbers easily
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 8 - i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

void randomise()
{

    //Randomise every time the code is ran
    srand(time(0));

    int number = (rand() % 9) + 1;
    int row = (rand() % 9) + 1, column = (rand() % 9) + 1;
    int counter = 0;

    while(counter != 20)
    {
        if (grid[row][column] != number)
        {
            grid[row][column] = number;

            for (int j = 0; j < 9; j++)
            {
                if (grid[row][j] == number)
                {
                    counter++;
                }
            }
        }
        for (int i = 0; i < 9; i++) 
        {
            if (grid[i][column] == number)
            {
                    counter++;
            }
        }
    }
}

int checkResult() 
{

    if (checkGrid() == 0) 
    {
        return 0;
    }
    return 1;
}

void drawSudoki()
{
    randomise();
    while (1) {
        system("cls");

        sudokuTemplate();
        while (play() != 0) 
        {
            if (checkResult() == 0) 
            {
                cout << "Congratulations!\n";
                sudokuTemplate();
                break;
            }
        }

        grid[row][col] = num;

    }
}