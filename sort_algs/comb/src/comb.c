#include <stdio.h>
#include <stdlib.h>

#define STDIN_FILENO 0

void print_list(int qtd, int data[]) {
  for (int i = 0; i < qtd; i++) {
    printf("%02d", data[i]);
    if (i == qtd -1) printf("\n");
    else printf(", ");
  }
}

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main(int argc, char *argv[]) {
  int data[] = {2, 3, 1, 5, 20, 8, 2, 0, 1, 6, 19, 9, 2, 3, 1, 6, 19, 8};
  int size = sizeof(data)/sizeof(int);
  print_list(size, data);


  int step = size;
  int changed;
  do {
    step = step / 1.3;
    if (step < 1) step = 1;
    changed = 0;
    for (int i = 0; i < size-step; i++) {
      print_list(size, data);
      int j = i + step;
      if (data[i] > data[j]) {
        swap(&data[i], &data[j]);
        changed = 1;
      }
      printf("step = %d, changed = %d, i = %d (%d), j = %d (%d);\n", step, changed, i, data[i], j, data[j]);
    }
  } while (changed || step != 1);

}
