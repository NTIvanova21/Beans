#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include "sudoku.h"

using namespace std;

#define KEY_ENTER 13
#define KEY_ESC 27
#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_DOWN 80
#define KEY_N 110
#define KEY_Y 121

void pointerChange();

void drawSudokiMenu();

void drawDifficultyMenu();

void drawHelpMenu();

void drawExitGame();

void drawMenu();

void addTwentyFiveSpaces();

void addFiftyFiveSpaces();

void addHundredAndTwentyDashes();
