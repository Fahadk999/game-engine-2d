#include "functions.h"

void foodGen(int& foodX, int& foodY, int WIDTH, int HEIGHT)
{
    foodX = 1 + (rand() % (WIDTH-2));
    foodY = 1 + (rand() % (HEIGHT-2));
}
bool input(int& playerX, int& playerY, int& direction)
{
    if(_kbhit())
    {
        switch(_getch())
        {
            case 'a': playerX--; direction = 2; return true; break;
            case 'd': playerX++; direction = 1; return true; break;
            case 'w': playerY--; direction = 3; return true; break;
            case 's': playerY++; direction = 4; return true; break;
        }
    }
    return false;
}


