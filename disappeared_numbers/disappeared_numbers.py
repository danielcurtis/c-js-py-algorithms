# Find numbers that do not appear in array [1,n]
# Example: [4,3,2,7,8,2,3,1] returns [5,6]
# Iterate over numbers and mark them as negative


def disappeared_numbers(nums):
    nums = [0] + nums
    for i in range(len(nums)):
        index = abs(nums[i])
        nums[index] = -abs(nums[index])

    return [i for i in range(len(nums)) if nums[i] > 0]


print(disappeared_numbers([4, 3, 2, 7, 8, 2, 3, 1]))
