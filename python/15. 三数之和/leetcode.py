from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        re = []
        length = len(nums)
        if length < 3:            # 如果数组长度小于3直接返回
            return re

        nums.sort()               # 对数组进行排序
        for i in range(length - 2):
            if nums[i] > 0: return re   # 如果nums[i]大于0则数组肯定会大于0
            if i > 0 and nums[i - 1] == nums[i]: continue  # 排除重复的元素

            left = i + 1
            right = length - 1
            while left < right:
                tmp = nums[i] + nums[left] + nums[right]
                if tmp == 0:
                    re.append([nums[i], nums[left], nums[right]])
                    left += 1  # 添加数组后,left向右进一位
                    while left < right and nums[left - 1] == nums[left]: left += 1  # left < right防止越界
                if tmp > 0:
                    right -= 1
                    while left < right and nums[right + 1] == nums[right]: right -= 1
                if tmp < 0:
                    left += 1
                    while left < right and nums[left - 1] == nums[left]: left += 1
        return re

a = [-2,-3,0,0,-2]
b = Solution().threeSum(a)
for i in b:
    print(i)
