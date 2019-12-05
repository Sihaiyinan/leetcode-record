from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        m = {}
        for i, num in enumerate(nums):
            if target - num in m:
                return [m[target - num], i]
            m[num] = i

print(Solution().twoSum([3, 2, 4], 6))
