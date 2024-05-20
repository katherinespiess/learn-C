#ifndef LINKDELIST_H
#define LINKDELIST_H

typedef struct SingleLinkedNode {
  struct SingleLinkedNode *next;
  void *data;
} SingleLinkedNode;

typedef struct SingleLinkedList {
  struct SingleLinkedNode *head;
  int len;
} SingleLinkedList;


/**
 * @returns a new instance of SingleLinkedList, initialized.
 */
SingleLinkedList* singleLL_make();

/**
 * Adds an element to the list
 *
 * @param list is the list that will receive a new item.
 * @param data is the pointer to the data that we're storing in the list.
 * @returns 0 if the appending is successful and 1 otherwise.
 */
int singleLL_append(struct SingleLinkedList* list, void* data);

/**
 * Accesses and removes the first element of the list.
 *
 * @param list the list from which to remove the top.
 * @return the data at the top of the list, NULL if there is none.
 */
void* singleLL_pop(struct SingleLinkedList* list);

/**
 * Accesses the first element in the list without changing it.
 *
 * @param list the list from which to pick the first element.
 * @return the first element in the list.
*/
void* singleLL_peek(struct SingleLinkedList* list);


typedef struct DoubleLinkedNode {
  struct DoubleLinkedNode *next;
  struct DoubleLinkedNode *prev;
  void *data;
} DoubleLinkedNode;

typedef struct DoubleLinkedList {
  struct DoubleLinkedNode *head;
  struct DoubleLinkedNode *tail;
  int len;
} DoubleLinkedList;

/**
 * @returns a new instance of DoubleLinkedList, initialized.
 */
DoubleLinkedList* doubleLL_make();

/**
 * Adds an element to the beginning of the list
 *
 * @param list is the list that will receive a new item.
 * @param data is the pointer to the data that we're storing in the list.
 * @returns 0 if the appending is successful and 1 otherwise.
 */
int doubleLL_shift(struct DoubleLinkedList* list, void* data);

/**
 * Adds an element to the tail of the list
 *
 * @param list is the list that will receive a new item.
 * @param data is the pointer to the data that we're storing in the list.
 * @returns 0 if the appending is successful and 1 otherwise.
 */
int doubleLL_append(struct DoubleLinkedList* list, void* data);

/**
 * Accesses and removes the element at the head end of the list
 *
 * @param list the list from which to remove the top.
 * @return the data at the top of the list, NULL if there is none.
 */
void* doubleLL_unshift(struct DoubleLinkedList* list);

/**
 * Accesses and removes the element at the tail end of the list
 *
 * @param list the list from which to remove the top.
 * @return the data at the top of the list, NULL if there is none.
 */
void* doubleLL_pop(struct DoubleLinkedList* list);


/**
 * Accesses the element at the tail end of the list
 *
 * @param list the list from which to pick the first element.
 * @return the first element in the list.
*/
void* doubleLL_peek(struct DoubleLinkedList* list);

/**
 * Accesses the element at the head of the list
 *
 * @param list the list from which to pick the first element.
 * @return the first element in the list.
*/
void* doubleLL_look(struct DoubleLinkedList* list);



#endif
