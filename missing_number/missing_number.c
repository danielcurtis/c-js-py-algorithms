#include <stdio.h>

int missing_number(int* nums, int numsSize) {
  int sum = 0;
  int tot = 0;

  for (int i = 0; i < numsSize; i++) {
    sum += nums[i];
    tot += i + 1;
  }

  return tot - sum;
}

int main(void) {
  int arr[9] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
  printf("%d\n", missing_number(arr, 9));

  return 0;
}