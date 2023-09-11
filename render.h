#ifndef RENDER_H
#define RENDER_H

#include "snake.h"
#include "food.h"

void initialize_screen();
void draw_board(int width, int height);
void draw_snake(Snake* snake);
void draw_food(Food* food);
void terminate_screen();

#endif // RENDER_H
