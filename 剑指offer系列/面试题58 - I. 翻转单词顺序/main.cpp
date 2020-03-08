// 面试题58 - I. 翻转单词顺序

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string reverseWords(string s) {
		if (s.empty()) 
			return s;
		string re;
		vector<string> tmp = split(s, ' ');
		if (tmp.empty())
			return re;
		for (int i = tmp.size() - 1; i > 0; --i)
		{
			re += tmp[i];
			re += ' ';
		}
		re += tmp[0];
		return re;
	}

	vector<string> split(const string &s, const char &c)
	{
		vector<string> re;
		if (s.empty()) return re;
		
		string t;
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == c)
			{
				if (!t.empty())
				{
					re.push_back(t);
					t.clear();
				}
				continue;
			}
			t.push_back(s[i]);
		}
		if (!t.empty())
			re.push_back(t);
		return re;
	}
};


int main()
{
	string s = " ", re;
	re = Solution().reverseWords(s);
	for (auto &i : re)
		cout << i;

	std::cout << std::endl;
	return 0;
}