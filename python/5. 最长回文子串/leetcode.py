class Solution:
	def longestPalindrome1(self, s: str) -> str:
		"""
		最大公共子串，超时
		"""
		maxlen = 0
		maxend = 0
		l = len(s)
		t = [[0] * l for _ in range(l)]
		for i in range(l):
			for j in range(l):
				if s[i] == s[l - j - 1]:
					if i == 0 or j == 0:
						t[i][j] = 1
					else:
						t[i][j] = t[i - 1][j - 1] + 1
				if t[i][j] > maxlen:
					before = l - 1 - j
					if before + t[i][j] - 1 == i:
						maxlen = t[i][j]
						maxend = i
		re = s[maxend - maxlen + 1: maxend + 1]
		return re


	def longestPalindrome(self, s: str) -> str:
		"""
		动态规划方法，超时
		"""
		if len(s) < 1:
			return s

		max_len = 0
		re = s[0]
		P = [[0 for _ in range(len(s))] for _ in range(len(s))]

		for j in range(len(s)):
			for i in range(j):
				if s[i] == s[j] and (j - i <= 2 or P[i + 1][j - 1]):
					P[i][j] = 1
					if j - i + 1 > max_len:
						max_len = j - i + 1
						re = s[i:j + 1]
		return re


string = 'babad'
a = Solution().longestPalindrome(s)
print(a)
