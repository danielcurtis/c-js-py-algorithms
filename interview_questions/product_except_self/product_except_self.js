// Given an array, return an array such that element N is equal to the product
// of all the elements except element N without division.
// Example: [1,2,3,4] returns [24,12,8,6]
// Solution: Multiply products to left of element N, then right of element N
// Time-complexity O(n); space-complexity O(n)

function product_except_self(nums) {
  const output = [];

  for (let i = 0, acc = 1; i < nums.length; i++) {
    output.push(acc);
    acc *= nums[i];
  }

  for (let i = nums.length - 1, acc = 1; i >= 0; i--) {
    output[i] *= acc;
    acc *= nums[i];
  }

  return output;
}

console.log(product_except_self([1, 2, 3, 4]));
