#include "arrayList.h"
#include <stdlib.h>


ArrayList* arrayL_make() {
  void** arr = malloc(sizeof(void*)*10);
  if (arr == NULL) return NULL;
  ArrayList* list = malloc(sizeof(ArrayList));
  if (list == NULL) return NULL;
  list->len = 0;
  list->max = 10;
  list->data = arr;
  return list;
}

void arrayL_destroy(ArrayList* list) {
  free(list->data);
  free(list);
}

int arrayL_append(struct ArrayList* list, void* data) {
  if (list->len == list->max) {
    void** arr = malloc(sizeof(void*)*list->max*2);
    if (arr == NULL) return 1;
    for (int i = 0; i < list->max; i++) {
      arr[i] = list->data[i];
    }
    free(list->data);
    list->data = arr;
    list->max = list->max * 2;
  }
  list->data[list->len] = data;
  list->len++;
  return 0;
}

void* arrayL_get(struct ArrayList* list, int pos) {
  if (pos < 0 || pos >= list->len) return NULL;
  return list->data[pos];
}

void* arrayL_set(struct ArrayList* list, int pos, void* data) {
  if (pos < 0 || pos >= list->len) return NULL;
  void* old = list->data[pos];

  list->data[pos] = data;

  return old;
}


void *arrayL_remove(struct ArrayList *list, int pos) {
  if (pos < 0 || pos >= list->len) return NULL;
  void* old = list->data[pos];

  //shift the data back
  for (int i = pos; i < list->len-1; i++) {
    list->data[i] = list->data[i+1];
  }
  list->len--;
  return old;
}
