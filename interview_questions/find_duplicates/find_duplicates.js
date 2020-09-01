// Find duplicates in array of numbers in O(n) time & O(1) space
// Example: [4,3,2,7,8,2,3,1] returns [2,3]
// Solution: Cycle through array marking numbers -1 that we've seen
// If immutability is an issue and O(1) space is not, use a Set instead

function find_duplicates(nums) {
  let ans = [];

  for (let i = 0; i < nums.length; i++) {
    // Get absolute val of current element
    let abs = Math.abs(nums[i]);

    // If negative (meaning we've seen it) push to ans
    // Else mark as negative
    if (nums[abs - 1] < 0) ans.push(abs);
    else nums[abs - 1] *= -1;
  }

  return ans;
}

console.log(find_duplicates([4, 3, 2, 7, 8, 2, 3, 1]));
