#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  int val;
  struct Node *next;
};

struct Set {
  int bucket_size;
  struct Node **table;
};

void init_set(struct Set *set, int bucket_size) {
  set->bucket_size = bucket_size;
  set->table = malloc(sizeof(struct Node *) * bucket_size);
  memset(set->table, 0, sizeof(struct Node *) * bucket_size);
}

bool add_value(struct Set *s, int val) {
  int idx = val > 0 ? val : -val;
  idx %= s->bucket_size;
  struct Node *ptr = s->table[idx];

  while (ptr != NULL) {
    if (ptr->val == val)
      return false;

    ptr = ptr->next;
  }

  ptr = malloc(sizeof(struct Node));
  ptr->val = val;
  ptr->next = s->table[idx];
  s->table[idx] = ptr;

  return true;
}

void release_set(struct Set *s) {
  struct Node *ptr, *tmp;

  for (int i = 0; i < s->bucket_size; ++i) {
    ptr = s->table[i];
    while (ptr != NULL) {
      tmp = ptr;
      ptr = ptr->next;
      free(tmp);
    }
  }

  free(s->table);
  s->table = NULL;
  s->bucket_size = 0;
}

bool contains_duplicate(int *nums, int numsSize) {
  if (numsSize < 2)
    return false;

  struct Set set;

  init_set(&set, numsSize / 2);

  for (int i = 0; i < numsSize; ++i) {
    if (!add_value(&set, nums[i])) {
      release_set(&set);
      return true;
    }
  }

  release_set(&set);

  return false;
}

int main(void) {
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1};
  bool ans = contains_duplicate(arr, 10);

  printf("%d\n", ans ? 1 : 0);

  return 0;
}