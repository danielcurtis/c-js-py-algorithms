// Find duplicates in array of numbers in O(n) time & O(1) space
// Example: [4,3,2,7,8,2,3,1] returns [2,3]
// Solution: Cycle through array marking numbers -1 that we've seen
// If immutability is an issue and O(1) space is not, use a Set instead
#include <stdio.h>
#include <stdlib.h>

void find_duplicates(int* nums, int numsSize) {
  int ans[numsSize];
  int cnt = 0;

  for (int i = 0; i < numsSize; i++) {
    int val = abs(nums[i]);

    if (nums[val - 1] < 0) {
      ans[cnt] = val;
      cnt++;
    } else {
      nums[val - 1] *= -1;
    }
  }

  for (int i = 0; i < cnt; i++)
    printf("%i\n", ans[i]);
}

int main(void) {
  int arr[8] = {4, 3, 2, 7, 8, 2, 3, 1};
  find_duplicates(arr, 8);

  return 0;
}