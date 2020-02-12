// 面试题05. 替换空格


#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
	string replaceSpace(string s) {
		if (s.empty()) return "";
		int len = s.size();
		int kg = 0;
		for (auto &i : s)   // 首先统计字符串中的空格数
		{
			if (i == ' ')
				++kg;
		}
		int new_len = len + kg * 2;
		for (int i = len; i < new_len; ++i)    // 扩大字符串的长度
			s += ' ';

		int index = new_len - 1;
		for (int i = len - 1; i >= 0; --i)   // 从后往前依次替换空格
		{
			if (s[i] != ' ')
				s[index--] = s[i];
			else
			{
				s[index--] = '0';
				s[index--] = '2';
				s[index--] = '%';
			}
		}
		return s;
	}
};

int main() 
{
	string s = "We are happy.";
	string re = Solution().replaceSpace(s);
	for (auto &i : re)
		cout << i;
	std::cout << endl;
	return 0;
}
