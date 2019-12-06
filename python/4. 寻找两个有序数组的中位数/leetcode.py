from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        """
        不满足O(log(m + n))
        """
        nums1 += nums2
        nums1.sort()
        return (nums1[len(nums1)//2 - 1] + nums1[len(nums1)//2])/2.0 if len(nums1) % 2 == 0 else nums1[len(nums1)//2] * 1.0

print(Solution().findMedianSortedArrays([1,3], [2]))


