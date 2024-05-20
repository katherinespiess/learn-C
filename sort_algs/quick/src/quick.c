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

void sort(int start, int end, int *data) {
  print_list(18, data);
  if (end-start<1) {
    /* printf("base case\n"); */
    //single value or no value
    return;
  }
  if (end-start == 1) {
    /* printf("base case, two items\n"); */
    //only two value
    if (data[end] < data[start]) {
      int temp = data[end];
      data[end] = data[start];
      data[start] = temp;
    }
    return;
  }
  printf("%d to %d, with %d as pivot\n", start, end, data[end]);

  //used value at end as pivot
  int left = start;
  int right = end-1;
  while (left <= right) {
    while (data[left] < data[end])
      left++;
    while (data[right] > data[end])
      right--;
    if (left > right)
      break;
    int temp = data[left];
    data[left] = data[right];
    data[right] = temp;
    left++;
    right--;
  }
  int temp = data[end];
  data[end] = data[left];
  data[left] = temp;
  sort(start, right, data);
  sort(left, end, data);
}

int main(int argc, char *argv[]) {
  int size = 18;
  int data[] = {2, 3, 1, 5, 20, 8, 2, 0, 1, 6, 19, 9, 2, 3, 1, 6, 19, 8};
  sort(0, size-1, data);


}
