from typing import List

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        """
        深度优先遍历
        """
        dic = {2: 'abc', 3: 'def', 4: 'ghi', 5: 'jkl', 6: 'mno',
               7: 'pqrs', 8: 'tuv', 9: 'wxyz'}
        re = []
        if len(digits) == 0:
            return re

        self.find_string(digits, dic, cur_string='', res=re)
        return re

    def find_string(self, sub_digits, dic, cur_string, res):
        if len(sub_digits) == 0:
            res.append(cur_string)
            return
        for i in dic[int(sub_digits[0])]:
            self.find_string(sub_digits[1:], dic, cur_string + i, res)

    def letterCombinations2(self, digits: str) -> List[str]:
        """
        广度优先遍历
        """
        dic = {2: 'abc', 3: 'def', 4: 'ghi', 5: 'jkl', 6: 'mno',
               7: 'pqrs', 8: 'tuv', 9: 'wxyz'}
        re = []
        if len(digits) == 0:
            return re

        re = ['']
        for num in digits:
            cur = []
            for old_string in re:
                for cur_str in dic[int(num)]:
                    cur.append(old_string + cur_str)
            re = cur
        return re



nums = '234'
b = Solution().letterCombinations2(nums)
print(b)