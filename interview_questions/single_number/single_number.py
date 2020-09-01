# Given an array of integers, every element appears twice except one. Return the one.
# Example: [4, 1, 2, 1, 2] returns 4
# Reduce the array by using the XOR operator
from functools import reduce


def single_number(nums):
    def xor(cur, nxt):
        return cur ^ nxt

    return reduce(xor, nums)


print(single_number([4, 1, 2, 1, 2]))
