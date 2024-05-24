#include "hashMap.h"
#include <criterion/criterion.h>

int id(void *i) { return *(int *)i; }

Test(HashMap, create) {
  HashMap *hmap = hMap_make(*id, 10);
  cr_assert_neq(hmap, NULL);
  hMap_destroy(hmap);
}

Test(hashMap, put) {
  HashMap *hmap = hMap_make(*id, 10);
  int i = 0;

  cr_assert_eq(hMap_put(hmap, (void *)&i, (void *)&i), 0);
  cr_assert_eq((int *)hMap_get(hmap, (void *)&i), &i);
  hMap_destroy(hmap);
}

Test(hashMap, colision) {
  HashMap *hmap = hMap_make(*id, 10);
  int i = 1;
  int j = 1;

  cr_assert_neq(&i, &j);

  cr_assert_eq(hMap_put(hmap, (void *)&i, (void *)&i), 0);
  cr_assert_eq(hMap_put(hmap, (void *)&j, (void *)&j), 0);

  cr_assert_eq((int *)hMap_get(hmap, (void *)&i), &i);
  cr_assert_eq((int *)hMap_get(hmap, (void *)&j), &j);
  hMap_destroy(hmap);
}

Test(hashMap, removal) {
  HashMap *hmap = hMap_make(*id, 10);
  int i = 1;

  cr_assert_eq(hMap_put(hmap, (void *)&i, (void *)&i), 0);
  cr_assert_eq((int *)hMap_get(hmap, (void *)&i), &i);
  cr_assert_eq(hMap_remove(hmap, (void *)&i), &i);
  cr_assert_eq((int *)hMap_get(hmap, (void *)&i), NULL);

  hMap_destroy(hmap);
}

Test(hashMap, len) {
  HashMap *hmap = hMap_make(*id, 10);
  int i = 1;
  int j = 2;

  cr_assert_eq(hmap->len, 0);
  cr_assert_eq(hMap_put(hmap, (void *)&i, (void *)&i), 0);
  cr_assert_eq(hmap->len, 1);
  cr_assert_eq(hMap_put(hmap, (void *)&j, (void *)&j), 0);
  cr_assert_eq(hmap->len, 2);
  cr_assert_eq(hMap_remove(hmap, (void *)&i), &i);
  cr_assert_eq(hmap->len, 1);

  hMap_destroy(hmap);
}

Test(hashMap, keys) {
  HashMap *hmap = hMap_make(*id, 10);
  int i = 1;
  int j = 2;

  cr_assert_eq(hMap_put(hmap, (void *)&i, (void *)&i), 0);
  cr_assert_eq(hMap_put(hmap, (void *)&j, (void *)&j), 0);

  void **keys;

  keys = hMap_keys(hmap);
  cr_assert_eq((int *)keys[0], &i);
  cr_assert_eq((int *)keys[1], &j);
  free(keys);

  cr_assert_eq(hMap_remove(hmap, (void *)&i), &i);

  keys = hMap_keys(hmap);
  cr_assert_eq((int *)keys[0], &j);
  free(keys);

  hMap_destroy(hmap);
}
