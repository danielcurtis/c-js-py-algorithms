# Find missing number in arr 0 < arr[n] < arr length
# Example: [9, 6, 4, 2, 3, 5, 7, 0, 1] returns 8
# Calculate difference between arr length and sum of arr vals


def missing_number(nums):
    s = 0
    t = 0

    for i in range(0, len(nums)):
        s += nums[i]
        t += i + 1

    return t - s


print(missing_number([9, 6, 4, 2, 3, 5, 7, 0, 1]))
