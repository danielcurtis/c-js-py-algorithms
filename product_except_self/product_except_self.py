# Given an array, return an array such that element N is equal to the product
# of all the elements except element N without division.
# Example: [1,2,3,4] returns [24,12,8,6]
# Solution: Multiply products to left of element N, then right of element N
# Time-complexity O(n); space-complexity O(n)


def product_except_self(nums):
    output = []

    acc = 1
    for i in range(len(nums)):
        output.append(acc)
        acc *= nums[i]

    acc = 1
    for i in range(len(nums) - 1, -1, -1):
        output[i] *= acc
        acc *= nums[i]

    return output


print(product_except_self([1, 2, 3, 4]))
