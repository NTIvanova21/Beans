#include <iostream>
#include <conio.h>

using namespace std;

#define KEY_ENTER 13
#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_DOWN 80

int pointer = 0, chose = 0;

void pointerChange()
{

    switch (_getch())
    {
    case KEY_UP:
        if (pointer == 0)
            pointer = 2;
        else
            pointer--;

        break;

    case KEY_DOWN:
        if (pointer == 2)
            pointer = 0;
        else
            pointer++;

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
        if (i == pointer)

            cout << ">>" << menu[i] << endl;

        else

            cout << menu[i] << endl;

    }
    pointerChange();
}

int main()
{
    while (chose == 0)
    {
        drawSudokiMenu();

    }
}