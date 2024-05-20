CC = gcc
CFLAGS = -Wall -Wextra 
#-Werror

SRCDIR = src
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = shaker

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

test: $(EXECUTABLE)
	cat assets/temp.txt | ./$(EXECUTABLE) | hexdump -C
