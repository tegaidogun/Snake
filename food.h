#ifndef FOOD_H
#define FOOD_H

typedef struct Food {
    int x;
    int y;
} Food;

Food* generate_food(int board_width, int board_height);

#endif // FOOD_H
