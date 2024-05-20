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

  int changed = 1;
  while(changed) {
    changed = 0;
    for (int i = 0; i < size-1; i++) {
      printf("%02d - ", i);
      print_list(size, data);
      if (data[i] > data[i+1]) {
        int temp = data[i];
        data[i] = data[i+1];
        data[i+1] = temp;
        changed = 1;
        printf("     ");
        print_list(size, data);
      }
    }
    if (!changed)
      break;
    for (int i = size-2; i >= 0; i--) {
      printf("%02d - ", i);
      print_list(size, data);
      if (data[i] > data[i+1]) {
        int temp = data[i];
        data[i] = data[i+1];
        data[i+1] = temp;
        changed = 1;
        printf("     ");
        print_list(size, data);
      }
    }
  }
}
