def contains_duplicate(nums):
    s = set()

    for num in nums:
        if (num in s):
            return True
        else:
            s.add(num)

    return False


print(contains_duplicate([1, 2, 3, 4, 5, 6, 7, 8, 9, 1]))
