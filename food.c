#include "food.h"
#include <stdlib.h>

Food* generate_food(int board_width, int board_height) {
    Food* food = (Food*)malloc(sizeof(Food));
    if (!food) {
        return NULL;
    }

    food->x = rand() % board_width;
    food->y = rand() % board_height;

    return food;
}
