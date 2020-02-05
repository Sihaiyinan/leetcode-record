"""
238. 除自身以外数组的乘积
"""
from typing import List

class Solution:
    def productExceptSelf1(self, nums: List[int]) -> List[int]:
        """
        左右表
        """
        size = len(nums)
        L, R, re = [0] * size, [0] * size, [0] * size

        L[0] = 1
        for i in range(1, size):
            L[i]  = L[i - 1] * nums[i - 1]

        R[-1] = 1
        for i in range(size - 1)[::-1]:
            R[i] = R[i + 1] * nums[i + 1]

        for i in range(size):
            re[i] = L[i] * R[i]

        return re

    def productExceptSelf(self, nums: List[int]) -> List[int]:
        """
        以返回数组代替左右表
        """
        size = len(nums)
        re = [0] * size

        re[0] = 1
        for i in range(1, size):
            re[i]  = re[i - 1] * nums[i - 1]

        R = 1
        for i in range(size)[::-1]:
            re[i] = re[i] * R
            R *= nums[i]

        return re


a = [1, 2, 3, 4]
print(Solution().productExceptSelf(a))



