
class Solution:
    def isValid(self, s: str) -> bool:
        dic = {'{': '}', '[': ']', '(': ')'}   # 建立一个对应的字典
        stack = []
        if len(s) % 2 == 1: return False       # 如果s的长度为奇数直接返回False
        for c in s:
            if len(stack) == 0 and c in [')', '}', ']']: return False    # 如果stack为空时字符为右括号直接返回False
            if c in ['(', '{', '[']:     # 如果字符为左括号加入stack
                stack.append(c)
            elif dic[stack.pop()] != c: return False   #如果右括号与stack中的第一个字符不匹配返回Fasle
        return len(stack) == 0

s = "()[]{}"
print(Solution().isValid(s))

