"""
215. 数组中的第K个最大元素
"""
from typing import List

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heap = nums[:k]
        for i in nums[k:]:
            heap.append(i)
            heap.remove(min(heap))
        return min(heap)

a = [3,2,1,5,6,8,7,4]
print(Solution().findKthLargest(a, 2))



