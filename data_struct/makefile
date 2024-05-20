CFLAGS = -Wno-implicit-function-declaration
CRITEREONFLAGS = -lcriterion


linkedListTest: linkedList.o linkedList.c
	gcc linkedList.c linkedListTest.c $(CRITEREONFLAGS) -o linkedListTest
	./linkedListTest
