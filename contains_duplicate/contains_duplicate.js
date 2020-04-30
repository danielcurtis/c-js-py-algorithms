function contains_duplicate(nums) {
  const set = new Set();

  for (let i = 0; i < nums.length; i++) {
    if (set.has(nums[i])) return true;
    else set.add(nums[i]);
  }

  return false;
}

console.log(contains_duplicate([1, 2, 3, 1]));
