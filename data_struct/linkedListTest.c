#include "linkedList.h"
#include <criterion/criterion.h>

Test(linkedList, flip) {
  SingleLinkedList *list = singleLL_make();
  int first;
  int secnd;
  cr_assert_eq(list->len, 0);
  singleLL_append(list, &first);
  cr_assert_eq(list->len, 1);
  singleLL_append(list, &secnd);
  cr_assert_eq(list->len, 2);
  cr_assert_eq(singleLL_peek(list), &secnd);
  cr_assert_eq(list->len, 2);
  cr_assert_eq(singleLL_pop(list), &secnd);
  cr_assert_eq(list->len, 1);
  cr_assert_eq(singleLL_peek(list), &first);
  cr_assert_eq(list->len, 1);
  cr_assert_eq(singleLL_pop(list), &first);
  cr_assert_eq(list->len, 0);
}


Test(DoubleLinkedList, queue) {
  DoubleLinkedList *list = doubleLL_make();
  void* first;
  void* secnd;
  cr_assert_eq(doubleLL_append(list, first), 0);
  cr_assert_eq(doubleLL_append(list, secnd), 0);
  cr_assert_eq(doubleLL_unshift(list), first);
  cr_assert_eq(doubleLL_unshift(list), secnd, "Last added should be last unshifted");
}


Test(DoubleLinkedList, recover) {
  DoubleLinkedList *list = doubleLL_make();
  int val = 1;
  doubleLL_append(list, &val);
  cr_assert_eq(*(int*)doubleLL_unshift(list), 1);
  val = 2;
  doubleLL_shift(list, &val);
  cr_assert_eq(*(int*)doubleLL_pop(list), 2);
}


Test(DoubleLinkedList, flip) {
  DoubleLinkedList *list = doubleLL_make();
  int first;
  int secnd;
  cr_assert_eq(doubleLL_append(list, &first), 0);
  cr_assert_eq(list->len, 1);
  cr_assert_eq(doubleLL_append(list, &secnd), 0);
  cr_assert_eq(list->len, 2);
  cr_assert_eq(doubleLL_peek(list), &secnd);
  cr_assert_eq(list->len, 2);
  cr_assert_eq(doubleLL_pop(list), &secnd);
  cr_assert_eq(list->len, 1);
  cr_assert_eq(doubleLL_peek(list), &first);
  cr_assert_eq(list->len, 1);
  cr_assert_eq(doubleLL_pop(list), &first);
  cr_assert_eq(list->len, 0);
}


