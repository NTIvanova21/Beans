#include "menu.h"

int arrow = 0;
bool chose = 0;

bool isGameRunning = true;

//Check in which position is the player
void pointerChange()
{

    //Detect which key is pressed
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

//Generate the Sudoki menu
void drawSudokiMenu()
{
    string menu[3] = { "Start", "Help", "Exit" };

    system("cls");

    cout << setw(76) << "+-------------------------------+" << endl;

    for (int i = 0; i < 43; i++)
    {
        cout << "-";
    }

    cout << "|" << setw(25) << "WELCOME TO SUDOKI!" << setw(7) << "|";

    for (int i = 0; i < 43; i++)
    {
        cout << "-";
    }
    cout << endl;

    cout << setw(76) << "+-------------------------------+" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << endl;
    }

    //Generate menu options
    for (int i = 0; i < 3; i++)
    {
        //Print ">>" to the current position
        if (i == arrow)

            cout << setw(60) << ">> " << menu[i] << endl << endl;

        else

            if (i == 0)
                cout << setw(62) << menu[i] << endl << endl;

            else

                cout << setw(61) << menu[i] << endl << endl;

    }
    pointerChange();

}

//Generate the Help menu
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

    // Add text about the goal of the game

    cout << endl << setw(75) << "The goal of the game" << endl << endl;

    cout << "\tThe goal of sudoku is simple: fill in the numbers 1-9 exactly once in every row, column, and 3x3 region." << endl;


    for (int i = 0; i < 120; i++) {
        cout << " ";
    }

    cout << endl << endl;

    // Add text about the rules

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

    //Detect if the ESC key is pressed
    switch (_getch())
    {
    case KEY_ESC:
        chose = 1;
        drawSudokiMenu();
        break;
    }
}

//Generate the Exit menu
void drawExitGame()
{
    system("cls");

    cout << "Are you sure? Y\\N";

    //Detect if the Y or N key is pressed
    switch (_getch())
    {
    case KEY_Y:
        isGameRunning = false;
        //Terminate program
        exit(0);

    case KEY_N:
        drawSudokiMenu(); break;
    }
}

int drawMenu()
{
    //Draw the menus before playing the sudoku
    while (isGameRunning)
    {
        while (chose == 0)
        {
            drawSudokiMenu();
        }

        chose = 0;

        //Stop the loop and start the sudoku
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