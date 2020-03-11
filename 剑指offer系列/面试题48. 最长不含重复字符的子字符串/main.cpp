// 面试题48. 最长不含重复字符的子字符串

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int re = 0, left = 0, right = 0;
		string sub;
		while (right < s.size())
		{
			int p = sub.find(s[right]);
			if (p != -1)
				left += p + 1;
			++right;
			sub = s.substr(left, right - left);
			if (sub.size() > re)
				re = sub.size();
		}
		return re;
	}
};


int main()
{
	string s = "abcabcbb";
	cout << Solution().lengthOfLongestSubstring(s) << endl;

	std::cout << std::endl;
	return 0;
}