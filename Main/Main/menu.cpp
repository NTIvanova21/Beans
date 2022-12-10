#include "menu.h"

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
    string menu[3] = {"Start", "Help", "Exit"};

    system("cls");

    cout << "Welcome to Sudoki noob version!";

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

void drawDifficultyMenu()
{

    string menu[3] = { "Easy", "Medium", "Hard" };

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

void drawHelpMenu()
{
    system("cls");
    // Add heading to the help menu

    cout << setw(71) << "+-------------+" << endl;

    for (int i = 0; i < 56; i++)
    {
        cout << "-";
    }

    cout << "|SUDOKU HELPER|";

    for (int i = 0; i < 49; i++)
    {
        cout << "-";
    }
    
    cout << endl << setw(71) << "+-------------+" << endl << endl;

    // Add text for what is sudoku

    cout << setw(72) << "What is a sudoku?" << endl << endl;

    cout << setw(97) << "The sudoku consists of a 9x9 grid further divided into nine 3x3 sub-grids." << endl;
    
    for (int i = 0; i < 120; i++) {
        cout << " ";
    }
    
    // Add text for what the goal of the game is

    cout << endl << setw(75) << "The goal of the game" << endl << endl;
    
    cout << "\tThe goal of sudoku is simple: fill in the numbers 1-9 exactly once in every row, column, and 3x3 region." << endl;


    for (int i = 0; i < 120; i++) {
        cout << " ";
    }

    cout << endl << endl;
    
    // Add text for the rules

    cout << "The rules:" << endl << endl;

    cout << "1. Use only numbers between 1 and 9." << endl;

    cout << "2. Don't repeat numbers in one of the box." << endl;

    cout << "3. You must have each number exactly once in every column and row." << endl;
   
    for (int i = 0; i < 120; i++) {
        cout << " ";
    }

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
        exit(0);

    case KEY_N:
        drawSudokiMenu(); break;
    }
}

int drawMenu() 
{
    while (isGameRunning)
    {
        while (chose == 0)
        {
            drawSudokiMenu();

        }

        chose = 0;

        if (arrow == 0)
        {
            isGameRunning = false;
            return 7;
        }
        else if (arrow == 1)
        {
            drawHelpMenu();
        }
        else if (arrow == 2)
        {
            drawExitGame();
        }
    }
    
}