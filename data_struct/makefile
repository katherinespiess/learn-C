

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CRITEREONFLAGS = -lcriterion

SRCDIR = .
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:.c=.o)

.PHONY: linkedListTest arrayListTest clan

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

test:
	$(CC) $(CFLAGS) $(CRITEREONFLAGS) $(SOURCES) -o test
	./test
	rm test
