// 面试题58 - II. 左旋转字符串

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	// 方法1
	string reverseLeftWords1(string s, int n) {
		if (s.empty())
			return "";
		string sub = s.substr(0, n);
		return s.substr(n, s.size() - n) + sub;
	}

	// 方法2
	string reverseLeftWords(string s, int n) {
		if (s.empty())
			return "";
		string re;
		
		for (int i = n; i < n + s.size(); ++i)
			re.push_back(s[i % s.size()]);
		return re;
	}
};

int main()
{
	string s = "abcdefg", re;
	re = Solution().reverseLeftWords(s, 2);

	std::cout << std::endl;
	return 0;
}