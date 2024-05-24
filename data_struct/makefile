

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

linkedListTest: linkedList.c linkedListTest.c
	$(CC) $(CFLAGS) $(CRITEREONFLAGS) linkedList.c linkedListTest.c -o linkedListTest
	./linkedListTest
	rm linkedListTest
  
arrayListTest: arrayList.c arrayListTest.c
	$(CC) $(CFLAGS) $(CRITEREONFLAGS) arrayList.c arrayListTest.c -o arrayListTest
	./arrayListTest
	rm arrayListTest
  
hashMapTest: hashMap.c hashMapTest.c
	$(CC) $(CFLAGS) $(CRITEREONFLAGS) hashMap.c hashMapTest.c arrayList.c -o hashMapTest
	./hashMapTest
	rm hashMapTest
  
