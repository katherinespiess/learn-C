#include "linkedList.h"
#include <stdlib.h>

SingleLinkedList* singleLL_make() {
  SingleLinkedList* list = malloc(sizeof(SingleLinkedList));
  list->head = NULL;
  list->len = 0;
  return list;
}

void singleLL_destroy(SingleLinkedList* list) {
  while (1) {
    if (singleLL_pop(list) == NULL) break;
  }
  free(list);
}

void* singleLL_pop(struct SingleLinkedList* list) {
  SingleLinkedNode *head = list->head;
  if (head == NULL) return NULL;
  list->len--;
  list->head = head->next;
  void* ptr = head->data;
  free(head);
  return ptr;
}

void* singleLL_peek(struct SingleLinkedList* list) {
  SingleLinkedNode *head = list->head;
  if (head == NULL) return NULL;
  return head->data;
}


int singleLL_append(struct SingleLinkedList* list, void* data) {
  SingleLinkedNode *head = (SingleLinkedNode*) malloc(sizeof(SingleLinkedNode));
  if (head == NULL) return 1;
  head->data = data;
  head->next = list->head;
  if (list->head == NULL) {
    list->len = 1;
  } else {
    list->len++;
  }
  list->head = head;
  return 0;
}

DoubleLinkedList* doubleLL_make() {
  DoubleLinkedList* list = malloc(sizeof(DoubleLinkedList));
  list->head = NULL;
  list->tail = NULL;
  list->len = 0;
  return list;
}

void doubleLL_destroy(DoubleLinkedList* list) {
  while (1) {
    if (doubleLL_pop(list) == NULL) break;
  }
  free(list);
}

void* doubleLL_unshift(struct DoubleLinkedList* list) {
  DoubleLinkedNode *node = list->head;

  list->head = node->next;
  if (list->head == NULL) {
    list->tail = NULL;
  } else {
    list->head->prev = NULL;
  }
  list->len--;


  void* ptr = node->data;
  free(node);
  return ptr;
}

void* doubleLL_pop(struct DoubleLinkedList* list) {
  DoubleLinkedNode *tail = list->tail;
  if (tail == NULL) return NULL;
  list->len--;
  list->tail = tail->prev;
  if (list->tail == NULL) list->head = NULL;
  void* ptr = tail->data;
  free(tail);
  return ptr;
}

void* doubleLL_peek(struct DoubleLinkedList* list) {
  DoubleLinkedNode *tail = list->tail;
  if (tail == NULL) return NULL;
  return tail->data;
}

void* doubleLL_look(struct DoubleLinkedList* list) {
  DoubleLinkedNode *head = list->head;
  if (head == NULL) return NULL;
  return head->data;
}


int doubleLL_shift(struct DoubleLinkedList* list, void* data) {
  DoubleLinkedNode *head = (DoubleLinkedNode*) malloc(sizeof(DoubleLinkedNode));
  if (head == NULL) return 1;
  head->data = data;
  head->next = list->head;
  head->prev = NULL;
  if (list->head == NULL) {
    list->len = 1;
    list->tail = head;
  } else {
    list->len++;
  }
  list->head = head;
  return 0;
}

int doubleLL_append(struct DoubleLinkedList* list, void* data) {
  DoubleLinkedNode *node = (DoubleLinkedNode*) malloc(sizeof(DoubleLinkedNode));
  if (node == NULL) return 1;
  node->data = data;
  node->prev = list->tail;
  node->next = NULL;
  if (list->tail == NULL) {
    list->head = node;
  } else {
    list->tail->next = node;
  }
  list->len++;
  list->tail = node;
  return 0;
}

