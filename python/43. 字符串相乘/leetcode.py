
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        re = ''
        if num1 == '0' or num2 == '0':
            return '0'

        s1, s2 = len(num1), len(num2)
        res = [0] * (s1 + 1) * (s2 + 1)     # 确保数组有足够的空间

        for i in range(s2):
            for j in range(s1):
                res[i + j] += int(num1[s1 - j - 1]) * int(num2[s2 - i - 1])

        # 处理多余的0
        for i in range(len(res))[::-1]:
            if res[i] == 0:
                res.pop(i)
            else:break

        # 处理进位问题
        for i in range(len(res)):
            if res[i] > 9 and i < len(res) - 1:
                res[i + 1] += res[i] // 10
                res[i] %= 10
        if res[-1] > 9:
            res.append(res[-1] // 10)
            res[-2] %= 10

        for i in res[::-1]:
            re += str(i)
        return re

a = '123456789'
b = '987654321'
print(Solution().multiply(a, b))