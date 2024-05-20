#include <stdio.h>
#include <stdlib.h>

int bubbleUp(int *data, int pos) {
  int cursor = pos;
  int parent = cursor << 1;
  while (cursor > 0 && data[parent] < data[cursor]) {
    int temp = data[parent];
    data[parent] = data[cursor];
    data[cursor] = temp;
    cursor = parent;
    parent = cursor << 1;
  }
  return 0;
}

int heapfy(int *data, int size) {
  for (int i = 1; i < size; i++)
    if (bubbleUp(data, i))
      return 1;
  return 0;
}

int main(int argc, char *argv[]) {
  int data[] = {7, 10, 11, 3, 1, 4, 3, 2, 4, 7, 9, 8};
  int size = 12;

  heapfy(data, size);
  
}
