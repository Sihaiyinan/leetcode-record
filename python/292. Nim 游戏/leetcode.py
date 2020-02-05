"""
292. Nim 游戏
"""

class Solution:
    def canWinNim(self, n: int) -> bool:
        return (n % 4) != 0

a = 8
print(Solution().canWinNim(a))



