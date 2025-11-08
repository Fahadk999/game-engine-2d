#include <iostream>
#include <windows.h>

#include "functions.h"

const int WIDTH = 50;
const int HEIGHT = 20;
char map[HEIGHT][WIDTH];
char head = '@';
char body = 'O';
char wall = '#';
char food = 'x';
int score = 0;
int lengthsize = 0;
static int direction = 1;
int previousX = 0;
int previousY = 0;
int bodyX = -1;
int bodyY = -1;

int main()
{
    srand(time(nullptr));
    int playerX = WIDTH/2;
    int playerY = HEIGHT/2;
    int foodX = 1 + (rand() % (WIDTH-1));
    int foodY = 1 + (rand() % (HEIGHT-1));
    // Gameloop
    while(true)
    {
        if (lengthsize > 0)
        {
            previousX = playerX;
            previousY = playerY;
        }
        if (!input(playerX, playerY, direction))
        {
            switch (direction)
            {
                case 1: playerX++; break;
                case 2: playerX--; break;
                case 3: playerY--; break;
                case 4: playerY++; break;
            }
        }
        if (lengthsize > 0)
        {
            bodyX = previousX;
            bodyY = previousY;
        }

        if (playerX < 0) playerX = WIDTH-1;
        if (playerX >= WIDTH) playerX = 0; 
        if (playerY < 0) playerY = HEIGHT-1;
        if (playerY >= HEIGHT) playerY = 0; 

        system("cls");
        for (int j = 0; j < HEIGHT; j++)
        {
            for (int i = 0; i < WIDTH; i++)
            {
                if (playerX == i && playerY == j) std::cout << head; 
                if (j == 0 || i == 0 || j == HEIGHT-1 || i == WIDTH-1) std::cout << wall;
                if (foodX == i && foodY == j) std::cout << food;
                else std::cout << ' ';
                
                if (lengthsize > 0)
                {
                    if (bodyX == i && bodyY == j) std::cout << body;
                }
                if (playerX == foodX && playerY == foodY) 
                {
                    foodGen(foodX, foodY, WIDTH, HEIGHT); 
                    score++;
                    lengthsize++;
                }
            }
            std::cout << '\n'; 
        }
        std::cout << "Score: " << score << '\n';
        Sleep(100);
    }
    std::cout << "GAMEOVER\n";
}
