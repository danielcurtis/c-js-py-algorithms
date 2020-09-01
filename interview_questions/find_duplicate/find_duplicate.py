# Return duplicate number in array in at least O(n^2) time
# and O(1) space complexity, without modifying array
# Example: [1,3,4,2,2] returns 2
# Solution: Could be solved with a set, like contains_duplicate,
# except for complexity requirements. Instead, use Floyd's Tortoise
# and Hare algorithm wikipedia.org/wiki/Cycle_detection


def find_duplicate(nums):
    tortoise = nums[0]
    hare = nums[0]

    while True:
        tortoise = nums[tortoise]
        hare = nums[nums[hare]]
        if tortoise == hare:
            break

    tortoise = nums[0]
    while tortoise != hare:
        tortoise = nums[tortoise]
        hare = nums[hare]

    return hare


print(find_duplicate([3, 1, 3, 4, 2]))
