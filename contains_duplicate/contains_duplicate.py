# Find duplicate number in arr when arr[n] > 0
# Example: [1, 2, 3, 1] returns true
# If set already has number, return true


def contains_duplicate(nums):
    s = set()

    for num in nums:
        if (num in s):
            return True
        else:
            s.add(num)

    return False


print(contains_duplicate([1, 2, 3, 4, 5, 6, 7, 8, 9, 1]))
