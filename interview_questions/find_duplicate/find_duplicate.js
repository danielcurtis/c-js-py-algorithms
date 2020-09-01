// Return duplicate number in array in at least O(n^2) time
// and O(1) space complexity, without modifying array
// Example: [1,3,4,2,2] returns 2
// Solution: Could be solved with a set, like contains_duplicate,
// except for complexity requirements. Instead, use Floyd's Tortoise
// and Hare algorithm wikipedia.org/wiki/Cycle_detection

function find_duplicate(nums) {
  let tortoise = nums[0];
  let hare = nums[0];
  do {
    tortoise = nums[tortoise];
    hare = nums[nums[hare]];
  } while (tortoise !== hare);

  tortoise = nums[0];
  while (tortoise !== hare) {
    tortoise = nums[tortoise];
    hare = nums[hare];
  }

  return hare;
}

console.log(find_duplicate([1, 3, 4, 2, 2]));
