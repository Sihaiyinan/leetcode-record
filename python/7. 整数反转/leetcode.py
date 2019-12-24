
class Solution:
    def reverse(self, x: int) -> int:
        INT_MIN = -0x80000000      # python的int比较长
        INT_MAX =  0x7FFFFFFF
        number = 0
        if x >= 0:
            while x:
                number = number * 10 + x % 10
                x = x // 10
            return 0 if number < INT_MIN or number > INT_MAX else number
        else:
            x = -x
            while x:
                number = number * 10 + x % 10
                x = x // 10
            return 0 if number < INT_MIN or number > INT_MAX else -number


a = -256
print(Solution().reverse(a))


