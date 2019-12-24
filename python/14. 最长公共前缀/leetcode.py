from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0: return ''                         # 如果数组为空直接返回
        re = strs[0]
        for i in range(1, len(strs)):                        # 从第二个字符串开始和re比较
            for j in range(min(len(re), len(strs[i]))):      # 以两个字符串中最短的长度为限
                if re[j] != strs[i][j]:                      # 如果循环还未结束发现不同的字符就更新re然后break
                    re = re[0:j]
                    break
            re = re if len(re) < len(strs[i]) else strs[i]   # 如果循环结束字符串都相同就以最短的字符串更新re
            if re == '':                                     # 如果re为空直接break
                break
        return re

string = ["aa","ab"]
print(Solution().longestCommonPrefix(string))

