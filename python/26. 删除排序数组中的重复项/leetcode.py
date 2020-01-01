from typing import List

class Solution:
	def removeDuplicates(self, nums: List[int]) -> int:
		if nums.__len__() == 0: return 0
		j = 0
		for i in range(1, nums.__len__()):
			if nums[j] != nums[i]:
				j += 1
				nums[j] = nums[i]
		return j + 1

nums = [0,0,1,1,1,2,2,3,3,4]
print(Solution().removeDuplicates(nums))