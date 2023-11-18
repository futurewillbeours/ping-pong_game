#include <stdio.h>
#include <stdlib.h>

void draw(int ballX, int ballY, int firstRacketPos, int secondRacketPos, int scoreLeft, int scoreRight);
int xball(int xb, int yb, int y1, int y2);
int yball(int yb, int diry);
int abs(int n);

int main(void) {
    int queue = 0, score1 = 0, score2 = 0, xb = 40, yb = 14, y1 = 14, y2 = 13, diry = 1;  // set default
                                                                                          // params
    char button;

    while (score1 != 21 && score2 != 21) {
        printf("\n");
        draw(abs(xb), abs(yb), y1, y2, score1, score2);
        if (queue % 2 == 0) {
            printf("\nEnter correct button (a, z or ' '): ");
            while (1 < 2) {
                scanf("%c", &button);
                if (button == 'a' || button == 'z' || button == ' ') break;
            }
        } else {
            printf("\nEnter correct button (k, m or ' '): ");
            while (1 < 2) {
                scanf("%c", &button);
                if (button == 'k' || button == 'm' || button == ' ') break;
            }
        }
        queue++;
        switch (button) {
            case 'z':
                if (y1 != 23) y1++;
                break;
            case 'a':
                if (y1 != 1) y1--;
                break;
            case 'm':
                if (y2 != 23) y2++;
                break;
            case 'k':
                if (y2 != 1) y2--;
                break;
        }
        if (xb == 80) {
            score1++;
            xb = 40, yb = 14, y1 = 13, y2 = 13;
            continue;
        } else if (xb == -1) {
            score2++;
            xb = 40, yb = 14, y1 = 13, y2 = 13;
            continue;
        } else {
            xb = xball(xb, yb, y1, y2);
            yb = yball(yb, diry);
        }
    }
    if (score1 == 21) printf("Player 1 won!");
    if (score2 == 21) printf("Player 2 won!");
}

int yball(int yb, int diry) {
    if (diry == 0) return yb;
    if (yb == 25 && diry == 1) yb = -yb;  // top collision
    if (yb == -1 && diry == 1) yb = -yb;  // bottom collision
    yb++;
    return yb;
}

void draw(int ballX, int ballY, int firstRacketPos, int secondRacketPos, int scoreLeft, int scoreRight) {
    system("clear");
    for (int i = 0; i < 27; i++) {
        if (i == 0 || i == 26) {
            for (int j = 0; j <= 82; j++) {
                if (j == 82) {
                    printf("\n");
                } else {
                    printf("*");
                }
            }
        } else {
            for (int j = 0; j <= 82; j++) {
                if (j == 0 || j == 81) {
                    printf("*");
                } else if (j == 82) {
                    printf("\n");
                } else if (((firstRacketPos == (i - 2)) || (firstRacketPos == (i - 1)) ||
                            (firstRacketPos == (i))) &&
                           (j == 1)) {
                    printf("]");
                } else if (((secondRacketPos == (i - 2)) || (secondRacketPos == (i - 1)) ||
                            (secondRacketPos == (i))) &&
                           (j == 80)) {
                    printf("[");
                } else if (ballX == j && ballY == i) {
                    printf("o");
                } else {
                    printf(" ");
                }
            }
        }
    }
    printf("%d:%d", scoreLeft, scoreRight);
}

int xball(int xb, int yb, int y1, int y2) {
    if (xb == 79 && yb >= y2 && yb <= (y2 + 2)) xb = -xb;
    if (xb == -2 && yb >= y1 && yb <= (y1 + 2)) xb = -xb;
    xb = xb + 1;
    return xb;
}
