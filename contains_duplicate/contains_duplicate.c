#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct list {
  int elm;
  struct list *next;
};

int list_contains(struct list *list, int n) {
  for (; list != NULL; list = list->next) {
    if (list->elm == n)
      return 1;
  }

  return 0;
}

struct set {
  int size;
  struct list *bs[256];
};

uint8_t hash(int n) {
  uint8_t h = 0;
  for (; n; n >>= 8)
    h ^= n & 0xff;

  return h;
}

int set_contains(struct set *s, int n) {
  return list_contains(s->bs[hash(n)], n);
}

int set_add(struct set *s, int n) {
  struct list **prev;
  for (prev = &s->bs[hash(n)]; *prev != NULL; prev = &(*prev)->next) {
    if ((*prev)->elm == n)
      return 0;
  }
  *prev = calloc(1, sizeof(struct list));
  (*prev)->elm = n;

  return ++s->size;
}

bool contains_duplicate(int *nums, int numsSize) {
  struct set *s = calloc(1, sizeof(struct set));

  for (int i = 0; i < numsSize; i++) {
    if (set_contains(s, nums[i]))
      return true;
    else
      set_add(s, nums[i]);
  }

  return false;
}

int main(void) {
  int arr[5] = {1, 5, -2, -4, 0};

  if (contains_duplicate(arr, 5))
    printf("true\n");
  else
    printf("false\n");

  return 0;
}