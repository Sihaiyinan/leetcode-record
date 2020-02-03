"""
88. 合并两个有序数组
"""
from typing import List

class Solution:
    def merge1(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        nums1_copy = nums1[0:m]
        nums1[:] = []

        p1, p2 = 0, 0
        while p1 < m and p2 < n:
            if nums1_copy[p1] < nums2[p2]:
                nums1.append(nums1_copy[p1])
                p1 += 1
            else:
                nums1.append(nums2[p2])
                p2 += 1
        nums1[p1 + p2:] = nums2[p2:] if p2 < n else nums1_copy[p1:]
        # return nums1

    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        p, p1, p2 = m + n - 1, m - 1, n - 1
        while p1 >= 0 and p2 >= 0:
            if nums1[p1] > nums2[p2]:
                nums1[p] = nums1[p1]
                p1 -= 1
            else:
                nums1[p] = nums2[p2]
                p2 -= 1
            p -= 1

        nums1[:p2 + 1] = nums2[:p2 + 1]

        # return nums1

a = [1, 2, 3, 0, 0, 0]
m = 3
b = [2, 5, 6]
n = 3
print(Solution().merge(a, m, b, n))
