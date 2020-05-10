// Given an array of integers, every element appears twice except one. Return the one.
// Example: [4,1,2,1,2] returns 4
// Reduce the array by using the XOR operator

function single_number(nums) {
  return nums.reduce((curr, next) => (curr ^= next));
}

console.log(single_number([4, 1, 2, 1, 2]));
