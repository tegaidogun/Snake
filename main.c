#include "snake.h"
#include "food.h"
#include "render.h"
#include "input.h"
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

#define BOARD_WIDTH 50
#define BOARD_HEIGHT 20

void move_snake(Snake* snake, int grow);
int check_collision(Snake* snake, Food* food);

int main() {
    initialize_screen();

    Snake* snake = initialize_snake(5);
    if (!snake) {
        terminate_screen();
        fprintf(stderr, "Failed to initialize snake\n");
        exit(EXIT_FAILURE);
    }

    Food* food = generate_food(BOARD_WIDTH, BOARD_HEIGHT);
    if (!food) {
        terminate_screen();
        fprintf(stderr, "Failed to generate food\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        clear();

        draw_board(BOARD_WIDTH, BOARD_HEIGHT);
        draw_snake(snake);
        draw_food(food);

        handle_input(snake);
        move_snake(snake, 0);

        int collision_result = check_collision(snake, food);
        if (collision_result == 1) {
            // Game over (wall collision or self-collision)
            mvprintw(BOARD_HEIGHT / 2, BOARD_WIDTH / 2 - 5, "GAME OVER");
            break;
        }

        refresh();
        usleep(100000); // Delay for 100 milliseconds
    }

    terminate_screen();
    return 0;
}

void move_snake(Snake* snake, int grow) {
    int new_x = snake->head->x;
    int new_y = snake->head->y;

    // Calculate new head position based on the current direction
    if (snake->direction == 0) new_y--;
    else if (snake->direction == 1) new_x++;
    else if (snake->direction == 2) new_y++;
    else if (snake->direction == 3) new_x--;

    // Create a new segment at the new head position
    Segment* new_head = (Segment*)malloc(sizeof(Segment));
    if (!new_head) {
        // Handle memory allocation failure
        return;
    }
    new_head->x = new_x;
    new_head->y = new_y;
    new_head->next = snake->head;

    snake->head = new_head;

    // If the snake has eaten food, it grows, so we don't remove a tail segment
    if (!grow) {
        // Find the second to last segment
        Segment* current = snake->head;
        while (current->next != snake->tail) {
            current = current->next;
        }

        // Remove the tail segment
        current->next = NULL;
        free(snake->tail);
        snake->tail = current;
    } else {
        snake->length++;
    }
}


int check_collision(Snake* snake, Food* food) {
    // Check wall collision
    if (snake->head->x < 1 || snake->head->x >= BOARD_WIDTH ||
        snake->head->y < 1 || snake->head->y >= BOARD_HEIGHT) {
        return 1; // Wall collision
    }

    // Check self-collision
    Segment* current = snake->head->next;
    while (current != NULL) {
        if (snake->head->x == current->x && snake->head->y == current->y) {
            return 1; // Self-collision
        }
        current = current->next;
    }

    // Check food collision
    if (snake->head->x == food->x && snake->head->y == food->y) {
        move_snake(snake, 1); // Grow the snake
        food->x = rand() % BOARD_WIDTH; // Generate new food
        food->y = rand() % BOARD_HEIGHT;
        return 0;
    }

    return 0; // No collision
}

