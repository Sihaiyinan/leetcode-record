"""
46. 全排列
"""
from typing import List

class Solution:
    def fun(self, sub_nums, cur_res):
        """
        回溯函数
        :param sub_nums: 数组中剩余的元素
        :param cur_res: 待返回数组中已有的元素
        :return:
        """
        if len(sub_nums) == 1:     # 当数组中只剩一个元素的时候直接添加到待返回数组中
            res = cur_res.copy()   # 将cur_res中的元素拷贝到res中，确保回溯的时候不重复
            res.append(sub_nums[0])
            self.re.append(res)
            return
        for i in sub_nums:
            cur_res.append(i)
            tmp = sub_nums.copy()  # 剔除数组中的当前元素
            tmp.remove(i)
            self.fun(tmp, cur_res)
            cur_res.pop()   # 将当前 i 弹出，便于下一个 i 压入

    def permute(self, nums: List[int]) -> List[List[int]]:
        if nums.__len__() == 0: return [[]]
        self.re, res = [], []
        self.fun(nums, res)
        return self.re

a = [1, 2, 3]
print(Solution().permute(a))
