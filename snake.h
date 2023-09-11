#ifndef SNAKE_H
#define SNAKE_H

typedef struct Segment {
    int x;
    int y;
    struct Segment* next;
} Segment;

typedef struct Snake {
    Segment* head;
    Segment* tail;
    int length;
    int direction; // 0: UP, 1: RIGHT, 2: DOWN, 3: LEFT
} Snake;

Snake* initialize_snake(int initial_length);

#endif // SNAKE_H
