// Find numbers that do not appear in array [1,n]
// Example: [4,3,2,7,8,2,3,1] returns [5,6]
// Iterate over numbers and mark them as negative
// or create set and compare (less loops)

// O(n) time-complexity, O(1) space-complexity
function disappeared_numbers(nums) {
  for (let i = 0; i < nums.length; i++) {
    const x = Math.abs(nums[i]) - 1;
    if (nums[x] > 0) nums[x] = -nums[x];
  }

  let ans = [];

  for (let i = 0; i < nums.length; i++) {
    if (nums[i] > 0) ans.push(i + 1);
  }

  return ans;
}

// O(n) time-complexity, O(n) space-complexity (faster run-time)
function disappeared_numbers_other(nums) {
  const set = new Set(nums);
  let ans = [];

  for (let i = 1; i < nums.length + 1; i++) {
    if (!set.has(i)) ans.push(i);
  }

  return ans;
}

console.log(disappeared_numbers([4, 3, 2, 7, 8, 2, 3, 1]));
