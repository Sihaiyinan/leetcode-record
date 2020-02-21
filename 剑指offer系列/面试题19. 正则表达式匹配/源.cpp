// 面试题19. 正则表达式匹配
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		return matchCore(s, 0, p, 0);
	}

	bool matchCore(const string &s, int sp, const string &p, int pp)
	{
		if ((sp == s.size()) && (pp == p.size()))    // 当字符串匹配完且模式匹配完时，返回真
			return true;
		if ((sp != s.size()) && (pp == p.size()))    // 当字符串没匹配完但是模式匹配完时，返回假；
			return false;

		if (p[pp + 1] == '*')     // 当模式的下一个字符为*时分为三种情况，*前的字符不匹配，匹配1次和匹配多次
		{
			if (p[pp] == s[sp] || (p[pp] == '.' && (sp != s.size())))      // 如果当前字符串中的字符和模式中的字符匹配
				return matchCore(s, sp + 1, p, pp + 2)  // 等于*号前边的字符只匹配一次
				|| matchCore(s, sp + 1, p, pp)    // *前边的字符需要匹配多次
				|| matchCore(s, sp, p, pp + 2);   // *前的字符匹配0次
			else
				return matchCore(s, sp, p, pp + 2);
		}
		if (s[sp] == p[pp] || (p[pp] == '.' && (sp != s.size())))
			return matchCore(s, sp + 1, p, pp + 1);

		return false;
	}
};

int main() 
{
	string s = "", p = ".*";
	cout << Solution().isMatch(s, p) << endl;


	std::cout << endl;
	return 0;
}
