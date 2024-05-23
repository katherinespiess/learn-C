#include "arrayList.h"
#include <criterion/criterion.h>

Test(linkedList, resize) {
  ArrayList* list = arrayL_make();
  cr_assert_neq(list, NULL);

  int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  cr_assert_eq(arrayL_append(list, &data[0]), 0);
  cr_assert_eq(arrayL_append(list, &data[1]), 0);
  cr_assert_eq(arrayL_append(list, &data[2]), 0);
  cr_assert_eq(arrayL_append(list, &data[3]), 0);
  cr_assert_eq(arrayL_append(list, &data[4]), 0);
  cr_assert_eq(arrayL_append(list, &data[5]), 0);
  cr_assert_eq(arrayL_append(list, &data[6]), 0);
  cr_assert_eq(arrayL_append(list, &data[7]), 0);
  cr_assert_eq(arrayL_append(list, &data[8]), 0);
  cr_assert_eq(arrayL_append(list, &data[9]), 0);
  cr_assert_eq(arrayL_append(list, &data[10]), 0);

  cr_assert_eq(*(int*)arrayL_get(list, 10), data[10]);
  cr_assert_eq(list->len, 11);
  cr_assert_eq(list->max, 20);

  arrayL_destroy(list);
}


Test(linkedList, set) {
  ArrayList* list = arrayL_make();

  int i = 0;
  int j = 1;

  arrayL_append(list, (void*) &i);

  arrayL_set(list, 0, (void*) &j);

  
  cr_assert_eq(*(int*)arrayL_get(list, 0), 1);

  arrayL_destroy(list);
}
