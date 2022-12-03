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



void drawHelpMenu()
{
    system("cls");

    cout << "To play game be good at game!";

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