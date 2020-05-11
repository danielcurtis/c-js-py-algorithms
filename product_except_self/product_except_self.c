// Given an array, return an array such that element N is equal to the product
// of all the elements except element N without division.
// Example: [1,2,3,4] returns [24,12,8,6]
// Solution: Multiply products to left of element N, then right of element N
// Time-complexity O(n); space-complexity O(n)
#include <stdio.h>
#include <string.h>

void product_except_self(int nums[], int size) {
  int output[4] = {};

  int acc = 1;
  int i = 0;
  for (; i < size; i++) {
    output[i] = acc;
    acc *= nums[i];
  }

  acc = 1;
  i = size - 1;
  for (; i >= 0; i--) {
    output[i] *= acc;
    acc *= nums[i];
  }

  memcpy(nums, output, size);
}

int main(void) {
  int size = 4;
  int arr[4] = {1, 2, 3, 4};

  product_except_self(arr, size);

  for (int i = 0; i < size; i++)
    printf("%i ", arr[i]);

  return 0;
}