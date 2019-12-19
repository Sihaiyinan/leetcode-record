
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_len, l, r = 0, 0, 0
        sub = ''
        while r < len(s):
            sr = s[r]
            if sr in sub:
                index = sub.index(sr)
                l += index + 1
            r += 1
            sub = s[l:r]
            if len(sub) > max_len:
                max_len = len(sub)
        return max_len

print(Solution().lengthOfLongestSubstring("abcabcbb"))

