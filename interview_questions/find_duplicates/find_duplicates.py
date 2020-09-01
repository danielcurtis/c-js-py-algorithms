# Find duplicates in array of numbers in O(n) time & O(1) space
# Example: [4,3,2,7,8,2,3,1] returns [2,3]
# Solution: Cycle through array marking numbers -1 that we've seen
# If immutability is an issue and O(1) space is not, use a Set instead


def find_duplicates(nums):
    ans = []

    for num in nums:
        if nums[abs(num) - 1] < 0:
            ans.append(abs(num))
        else:
            nums[abs(num) - 1] *= -1

    return ans


print(find_duplicates([4, 3, 2, 7, 8, 2, 3, 1]))
