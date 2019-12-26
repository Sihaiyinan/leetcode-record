from typing import List

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        """
        与三数之和相似
        """
        nums.sort()            # 对数组进行排序
        closest = 0x7FFFFFFF   # 设置最接近的数
        re = target
        for i in range(len(nums) - 2):
            if i > 0 and nums[i - 1] == nums[i]: continue   # 跳过连续相同的数
            left = i + 1
            right = len(nums) - 1
            while left < right:
                tmp = nums[i] + nums[left] + nums[right]
                cha = tmp - target
                if cha == 0:                    # 如果三数之和与target相等直接返回
                    return target
                if abs(cha) < closest:          # 看看之差的绝对值是否小于已有的结果
                    closest = abs(cha)
                    re = tmp
                if cha < 0:
                    left += 1
                    while left < right and nums[left - 1] == nums[left]: left += 1
                if cha > 0:
                    right -= 1
                    while left < right and nums[right + 1] == nums[right]: right -= 1
        return re


a = [0,0,0]
b = 1
print(Solution().threeSumClosest(a, b))


