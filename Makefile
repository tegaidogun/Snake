CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g
LDFLAGS = -lncurses
OBJFILES = main.o snake.o food.o render.o input.o
TARGET = snake_game

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET)

.PHONY: all clean
