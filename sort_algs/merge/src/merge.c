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

void merge(int start, int size, int *data) {
  printf("merge %d items starting at %d\n", size, start);
  print_list(18, data);
  int* temp = malloc(size*sizeof(int));
  int left = start;
  int right = start+size/2;
  int left_end = right;
  int right_end = start+size;
  printf("Left is at %d to %d. ", left, left_end);
  printf("Right is at %d to %d.\n", right, right_end);
  for (int i = 0; i < size; i++) {
    if (left>=left_end) {
      printf("%d out of bounds; ", left);
      temp[i] = data[right];
      right++;
      continue;
    }
    if (right >= right_end) {
      printf("%d out of bounds; ", right);
      temp[i] = data[left];
      left++;
      continue;
    }
    if (data[left] < data[right]) {
      printf("%d < %d; ", data[left], data[right]);
      temp[i] = data[left];
      left++;
    } else {
      printf("%d >= %d; ", data[left], data[right]);
      temp[i] = data[right];
      right++;
    }
  }
  printf("\n");
  for (int i = 0; i < size; i++) {
    data[start+i] = temp[i];
  }
  free(temp);
  print_list(18, data);
}

void sort(int start, int size, int *data) {
  /* printf("sort %d items starting at %d\n", size, start); */
  //sort from start to start + size (exclusive)
  if (size == 1)
    return;//trivaly sorterted.
  sort(start, size/2, data);
  sort(start+size/2, size-size/2, data);
  merge(start, size, data);
}

int main(int argc, char *argv[]) {
  int size =  18;
  int data[] = {4, 3, 2, 1, 10, 0, 0, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7};
  sort(0, size, data);

}
