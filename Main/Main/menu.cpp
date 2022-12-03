#include "menu.h"

int arrow = 0, chose = 0;

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
    char menu[3][6] = { "Start", "Help", "Exit" };

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
        drawSudokiMenu(); break;
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

void drawMenu() {
    while (isGameRunning)
    {
        while (chose == 0)
        {
            drawSudokiMenu();

        }

        chose = 0;

        if (arrow == 0)
        {
            while (chose == 0)
            {
                drawDifficultyMenu();
            }
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