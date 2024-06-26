#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef struct ArrayList {
  int len;
  int max;
  void **data;
} ArrayList;

/**
 * @returns a new instance of SingleLinkedList, initialized.
 */
ArrayList *arrayL_make();

/**
 * Destroy/free the all references;
 */
void arrayL_destroy(ArrayList *list);

/**
 * Adds an element to the list
 *
 * @param list is the list that will receive a new item.
 * @param data is the pointer to the data that we're storing in the list.
 * @returns 0 if the appending is successful and 1 otherwise.
 */
int arrayL_append(struct ArrayList *list, void *data);

/**
 * Fetches the data at a certain position
 *
 * @param list the list from witch to get the value
 * @param pos the position of the record
 */

/**
 * Get the value at a given position
 *
 * @param list is the list from which to get the item
 * @param pos is the position where to get
 * @returns the data at the given position if pos is valid, NULL otherwise
 */
void *arrayL_get(struct ArrayList *list, int pos);

/**
 * Override an element at the list
 *
 * @param list is the list that will receive a new item.
 * @param pos is the position where to set
 * @returns the data at the given position if pos is valid, NULL otherwise
 */
void *arrayL_set(struct ArrayList *list, int pos, void *data);

/**
 * Removes the item at a given position
 * @param list the list from witch to remove the item.
 * @param pos the position of the value to remove
 * @returns the value that was removed
 */
void *arrayL_remove(struct ArrayList *list, int pos);

#endif
