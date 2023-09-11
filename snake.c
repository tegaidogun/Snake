#include "snake.h"
#include <stdlib.h>

Snake* initialize_snake(int initial_length) {
    Snake* snake = (Snake*)malloc(sizeof(Snake));
    if (!snake) {
        return NULL;
    }

    snake->length = initial_length;
    snake->direction = 1; // Initial direction to RIGHT

    Segment* head = (Segment*)malloc(sizeof(Segment));
    if (!head) {
        free(snake);
        return NULL;
    }

    head->x = initial_length;
    head->y = initial_length;
    head->next = NULL;

    snake->head = head;
    snake->tail = head;

    return snake;
}
