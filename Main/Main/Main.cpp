#include "menu.h"
#include "sudoki.h"

int main()
{
    int result;
    result = drawMenu();
    drawMenu();
    if (result == 7) {
        drawSudoki();
    }
}