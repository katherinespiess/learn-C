#ifndef HASHMAP_H
#define HASHMAP_H

#include "arrayList.h"

typedef struct HashMapEntry {
  void *key;
  void *value;
} HashMapEntry;

typedef struct HashMap {
  int (*hasher)(void *);
  int arrLen;
  int len;
  ArrayList **arr;
} HashMap;

/**
 * @returns a new instance of HashMap, initialized.
 * @param hasher the hashing function to be used.
 * @param arrLen the arrLen of the internal array.
 */
HashMap *hMap_make(int (*hasher)(void *), int arrLen);

/**
 * Destroy/free the all references;
 *
 * @param hmap the map to be destroyed
 */
void hMap_destroy(HashMap *hmap);

/**
 * Put a new entry into the map
 * @param hmap the map to which add the entry
 * @param key the key
 * @param val the value
 * @returns 1 if fails to allocate memory or hmap is null, zero otherwise
 */
int hMap_put(HashMap *hmap, void *key, void *val);

/**
 * Get the value assigned to a given key
 * @param hmap the map from which to get the value
 * @param key the key
 * @returns the data or null if missing key
 */
void *hMap_get(HashMap *hmap, void *key);

/**
 * remove the entry assigned to a given key
 * @param hmap the map from which to get the value
 * @param key the key
 * @returns the data or null if missing key
 */
void *hMap_remove(HashMap *hmap, void *key);

/**
 * Gather the keys into an array
 * @returns an array of pointers to the keys.
 */
void **hMap_keys(HashMap *hmap);

#endif
