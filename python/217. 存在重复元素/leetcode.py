"""
217. 存在重复元素
"""
from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        dic = {}
        for i in nums:
            if i in dic: return True
            dic[i] = 1
        return False

a = [1,2,3,1]
print(Solution().containsDuplicate(a))



