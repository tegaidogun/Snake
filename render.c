#include "render.h"
#include <ncurses.h>

void initialize_screen() {
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    timeout(100); // Set a timeout for the getch function
}

void draw_board(int width, int height) {
    for (int i = 0; i < width; i++) {
        mvprintw(0, i, "-");
        mvprintw(height, i, "-");
    }

    for (int i = 0; i < height; i++) {
        mvprintw(i, 0, "|");
        mvprintw(i, width, "|");
    }
}

void draw_snake(Snake* snake) {
    Segment* current = snake->head;
    while (current != NULL) {
        mvprintw(current->y, current->x, "O");
        current = current->next;
    }
}

void draw_food(Food* food) {
    mvprintw(food->y, food->x, "*");
}

void terminate_screen() {
    endwin();
}
