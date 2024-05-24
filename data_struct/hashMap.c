#include "hashMap.h"
#include "arrayList.h"
#include <stdlib.h>
#include <wctype.h>

HashMap *hMap_make(int (*hasher)(void *), int arrLen) {
  HashMap *hmap = (HashMap *)malloc(sizeof(HashMap));
  hmap->arrLen = arrLen;
  hmap->len = 0;
  hmap->hasher = hasher;
  hmap->arr = (ArrayList **)malloc(sizeof(ArrayList) * arrLen);

  for (int i = 0; i < arrLen; i++) {
    hmap->arr[i] = arrayL_make();
  }

  return hmap;
}

void hMap_destroy(HashMap *hmap) {
  if (hmap == NULL)
    return;
  for (int i = 0; i < hmap->arrLen; i++) {
    arrayL_destroy(hmap->arr[i]);
  }
  free(hmap->arr);
  free(hmap);
}

int hMap_put(HashMap *hmap, void *key, void *val) {
  if (hmap == NULL)
    return 1;
  int key_hash = hmap->hasher(key) % hmap->arrLen;

  ArrayList *bucket = hmap->arr[key_hash];
  for (int i = 0; i < bucket->len; i++) {
    HashMapEntry *entry = (HashMapEntry *)arrayL_get(bucket, i);
    if (entry->key == key) {
      entry->value = val;
      return 0;
    }
  }

  HashMapEntry *entry = (HashMapEntry *)malloc(sizeof(HashMapEntry));
  if (entry == NULL)
    return 1;
  entry->key = key;
  entry->value = val;

  arrayL_append(bucket, (void *)entry);
  hmap->len++;

  return 0;
}

void *hMap_get(HashMap *hmap, void *key) {
  if (hmap == NULL)
    return NULL;
  int key_hash = hmap->hasher(key) % hmap->arrLen;

  ArrayList *bucket = hmap->arr[key_hash];
  for (int i = 0; i < bucket->len; i++) {
    HashMapEntry *entry = (HashMapEntry *)arrayL_get(bucket, i);
    if (entry->key == key) {
      return entry->value;
    }
  }
  return NULL;
}

void *hMap_remove(HashMap *hmap, void *key) {

  if (hmap == NULL)
    return NULL;
  int key_hash = hmap->hasher(key) % hmap->arrLen;

  ArrayList *bucket = hmap->arr[key_hash];
  for (int i = 0; i < bucket->len; i++) {
    HashMapEntry *entry = (HashMapEntry *)arrayL_get(bucket, i);
    if (entry->key == key) {
      arrayL_remove(bucket, i);
      hmap->len--;
      return entry->value;
    }
  }
  return NULL;
}

void **hMap_keys(HashMap *hmap) {
  if (hmap == NULL)
    return NULL;
  void **keys;
  keys = (void **)malloc(sizeof(void *) * hmap->len);
  if (keys == NULL)
    return NULL;
  int j = 0;
  for (int i = 0; i < hmap->arrLen; i++) {
    ArrayList *bucket = hmap->arr[i];
    for (int i = 0; i < bucket->len; i++) {
      HashMapEntry *entry = (HashMapEntry *)arrayL_get(bucket, i);
      keys[j] = entry->key;
      j++;
    }
  }
  return keys;
}
