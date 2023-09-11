#include "input.h"
#include <ncurses.h>

void handle_input(Snake* snake) {
    int ch = getch();

    if (ch == KEY_UP && snake->direction != 2) {
        snake->direction = 0;
    } else if (ch == KEY_RIGHT && snake->direction != 3) {
        snake->direction = 1;
    } else if (ch == KEY_DOWN && snake->direction != 0) {
        snake->direction = 2;
    } else if (ch == KEY_LEFT && snake->direction != 1) {
        snake->direction = 3;
    }
}
