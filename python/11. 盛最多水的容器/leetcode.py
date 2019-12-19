from typing import List

class Solution:
	def maxArea(self, height: List[int]) -> int:
		re, l, r = 0, 0, len(height) - 1
		while r - l >= 1:
			t = (r - l) * min(height[l], height[r])
			if t > re:
				re = t
			if height[l] < height[r]:
				l += 1
			else:
				r -= 1
		return re

a = [1,8,6,2,5,4,8,3,7]
print(Solution().maxArea(a))

