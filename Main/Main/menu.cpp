#include "menu.h"
#include "sudoku.h"
#include <string>

int arrow = 0;
bool chose = 0, isMenuDrawn = 0;

bool isGameRunning = true;

void pointerChange()
{

    switch (_getch())
    {
    case KEY_UP:
        if (arrow == 0)
            arrow = 2;
        else
            arrow--;

        break;

    case KEY_DOWN:
        if (arrow == 2)
            arrow = 0;
        else
            arrow++;

        break;

    case KEY_ENTER:
        chose = 1;

        break;
    }
}

void drawSudokiMenu()
{
    string menu[3] = { "Start", "Help", "Exit" };
    int index = 0;

    system("cls");

    cout << "Welcome to Sudoki noob version!";

    for (int i = 0; i < 3; i++)
    {
        if (index == i)
        {
            cout << "> " << menu[i] << " <" << endl;
        }
        else
        {
            cout << menu[i] << endl;
        }
    }

}

void drawDifficultyMenu()
{

    char menu[3][7] = { "Easy", "Medium", "Hard" };

    system("cls");

    cout << "Choose dificulty man.";

    for (int i = 0; i < 5; i++)
    {
        cout << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        if (i == arrow)

            cout << ">>" << menu[i] << endl;

        else

            cout << menu[i] << endl;

    }
    pointerChange();
   
}

void drawBoard()
{
    system("cls");
    Table sudoku;
    int board[9][9]{
        {2, 3, 1, 4, 5, 6, 7, 8 , 9},
        {2, 3, 1, 4, 5, 6, 7, 8 , 9},
        {2, 3, 1, 4, 5, 6, 7, 8 , 9},
        {2, 3, 1, 4, 5, 6, 7, 8 , 9},
        {2, 3, 1, 4, 5, 6, 7, 8 , 9},
        {2, 3, 1, 4, 5, 6, 7, 8 , 9},
        {2, 3, 1, 4, 5, 6, 7, 8 , 9},
        {2, 3, 1, 4, 5, 6, 7, 8 , 9},
        {2, 3, 1, 4, 5, 6, 7, 8 , 9},
    };
    for (int i = 0; i < 9; i++)  
    {
        sudoku.add_row({ to_string(board[i][0]),  to_string(board[i][1]),  to_string(board[i][2]),
            to_string(board[i][3]),  to_string(board[i][4]),  to_string(board[i][5]),
            to_string(board[i][6]),  to_string(board[i][7]),  to_string(board[i][8])});
    }
    cout << sudoku;
}


void addTwentyFiveSpaces()
{
    for (int i = 0; i < 25; i++)
    {
        cout << " ";
    }
}

void addFiftyFiveSpaces()
{
    for (int i = 0; i < 55; i++)
    {
        cout << " ";
    }
}
void addHundredAndTwentyDashes()
{
    for (int i = 0; i < 120; i++)
    {
        cout << "-";
    }
}

void drawHelpMenu()
{
    system("cls");
    // Add heading to the help menu
    for (int i = 0; i < 56; i++)
    {
        cout << " ";
    }

    cout << "+-------------+" << endl;

    for (int i = 0; i < 56; i++)
    {
        cout << "-";
    }
    cout << "|SUDOKU HELPER|";
    for (int i = 0; i < 49; i++)
    {
        cout << "-";
    }
    cout << endl;
    for (int i = 0; i < 56; i++)
    {
        cout << " ";
    }
    cout << "+-------------+" << endl;

    cout << endl;

    // Add text for what is sudoku
    addFiftyFiveSpaces();

    cout << "What is a sudoku?" << endl;
    cout << endl;
    addTwentyFiveSpaces();

    cout << "The sudoku consists of a 9x9 grid further divided into nine 3x3 sub-grids." << endl;
    addHundredAndTwentyDashes();
    // Add text for what the goal of the game is
    cout << endl;

    addFiftyFiveSpaces();
    cout << "The goal of the game";
    
    for (int i = 0; i < 2; i++)
    {
        cout << endl;
    }
    cout << "\tThe goal of sudoku is simple: fill in the numbers 1-9 exactly once in every row, column, and 3x3 region." << endl;


    addHundredAndTwentyDashes();
    for (int i = 0; i < 2; i++)
    {
        cout << endl;
    }

    // Add text for the rules

    cout << "The rules:" << endl;
    cout << endl;

    cout << "1. Use only numbers between 1 and 9." << endl;

    cout << "2. Don't repeat numbers in one of the box." << endl;

    cout << "3. You must have each number exactly once in every column and row." << endl;
    addHundredAndTwentyDashes();

    for (int i = 0; i < 5; i++)
    {
        cout << endl;
    }

    cout << "Press [ESC] to go back...";

    switch (_getch())
    {
    case KEY_ESC:
        chose = 1;
        drawSudokiMenu();
        break;
    }
}

void drawExitGame()
{
    system("cls");

    cout << "Are you sure bestei? Y\\N";
    switch (_getch())
    {
    case KEY_Y:
        isGameRunning = false;
        system("exit"); break;

    case KEY_N:
        drawSudokiMenu(); break;
    }
}

void drawMenu() 
{
    string menu[3] = { "Start", "Help", "Exit" };

    while (isGameRunning)
    {
       
        if (_kbhit) 
        {

        }

    }
    
}