// Find missing number in arr 0 < arr[n] < arr length
// Example: [9, 6, 4, 2, 3, 5, 7, 0, 1] returns 8
// Calculate difference between arr length and sum of arr vals

function missing_number(nums) {
  let sum = 0;
  let tot = 0;

  for (let i = 0; i < nums.length; i++) {
    sum += nums[i];
    tot += i + 1;
  }

  return tot - sum;
}

console.log(missing_number([9, 6, 4, 2, 3, 5, 7, 0, 1]));
