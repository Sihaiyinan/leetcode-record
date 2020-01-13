
class Solution:
	def climbStairs(self, n: int) -> int:
		a, b, re = 0, 1, 0
		for i in range(n):
			re = a + b
			a = b
			b = re
		return re

n = 9
print(Solution().climbStairs(n))