"""
231. 2的幂
"""
class Solution:
    def isPowerOfTwo1(self, n: int) -> bool:
        if n == 0: return False
        while n % 2 == 0:
            n /= 2
        return n == 1

    def isPowerOfTwo2(self, n: int) -> bool:
        if n == 0: return False
        while True:
            if not (n & 1):
                n = n >> 1
                continue
            else:
                n = n >> 1
                return False if n else True

    def isPowerOfTwo(self, n: int) -> bool:
        return n > 0 and (n & (n - 1)) == 0

a = 256
print(Solution().isPowerOfTwo(a))



