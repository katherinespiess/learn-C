#include <stdio.h>
#include <stdlib.h>

#define STDIN_FILENO 0

void print_list(int qtd, int data[]) {
  for (int i = 0; i < qtd; i++) {
    printf("%02d", data[i]);
    if (i == qtd -1) {
      printf("\n");
    } else {
      printf(", ");
    }
  }
}

int main(int argc, char *argv[]) {
  int size = 18;
  int data[] = {2, 3, 1, 5, 20, 8, 2, 0, 1, 6, 19, 9, 2, 3, 1, 6, 19, 8};
  print_list(size, data);

  for (int i = 0; i < size-1; i++) {
    int min = i;
    for (int j = i + 1; j < size; j++) {
      if (data[j] < data[min]) {
        min = j;
      }
    }
    int temp = data[i];
    data[i] = data[min];
    data[min] = temp;
    print_list(size, data);
  }
}
