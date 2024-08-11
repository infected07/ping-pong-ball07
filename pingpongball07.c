#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

#define WIDTH 40
#define HEIGHT 20

int ballX, ballY, ballDirX, ballDirY;
int paddle1Y, paddle2Y;
int score1, score2;

void setup() {
    ballX = WIDTH / 2;
    ballY = HEIGHT / 2;
    ballDirX = -1;
    ballDirY = -1;
    paddle1Y = HEIGHT / 2 - 1;
    paddle2Y = HEIGHT / 2 - 1;
    score1 = 0;
    score2 = 0;
}

void draw() {
    system("cls");

    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0) printf("#");
            if (i == ballY && j == ballX) printf("O");
            else if (i >= paddle1Y && i <= paddle1Y + 2 && j == 1) printf("|");
            else if (i >= paddle2Y && i <= paddle2Y + 2 && j == WIDTH - 2) printf("|");
            else printf(" ");
            if (j == WIDTH - 1) printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++) printf("#");
    printf("\n");
    printf("Player 1: %d\n", score1);
    printf("Player 2: %d\n", score2);
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'w': paddle1Y--; break;
            case 's': paddle1Y++; break;
            case 'i': paddle2Y--; break;
            case 'k': paddle2Y++; break;
            case 'x': exit(0);
        }
    }
}

void logic() {
    ballX += ballDirX;
    ballY += ballDirY;

    if (ballY == 0 || ballY == HEIGHT - 1) ballDirY = -ballDirY;
    if (ballX == 1 && ballY >= paddle1Y && ballY <= paddle1Y + 2) ballDirX = -ballDirX;
    if (ballX == WIDTH - 2 && ballY >= paddle2Y && ballY <= paddle2Y + 2) ballDirX = -ballDirX;

    if (ballX == 0) {
        score2++;
        ballX = WIDTH / 2;
        ballY = HEIGHT / 2;
        ballDirX = -1;
        ballDirY = -1;
    }
    if (ballX == WIDTH - 1) {
        score1++;
        ballX = WIDTH / 2;
        ballY = HEIGHT / 2;
        ballDirX = -1;
        ballDirY = -1;
    }
}

int main() {
    setup();
    while (1) {
        draw();
        input();
        logic();
        Sleep(50);
    }
    return 0;
}