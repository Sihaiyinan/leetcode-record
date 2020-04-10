// 151. 翻转字符串里的单词

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<string> split(const string &str)
	{
		vector<string> res;
		if (str.empty()) return res;

		string re;
		for (auto &i : str)
		{
			if (i != ' ')
			{
				re += i;
			}
			else
			{
				if (!re.empty())
				{
					res.push_back(re);
					re.clear();
				}
			}
		}

		if (!re.empty())
		{
			res.push_back(re);
		}
		return res;
	}


	string reverseWords(string s) {
		vector<string> res = split(s);
		string t = "";
		if (res.empty()) return t;


		string re;
		for (auto it = res.begin(); it != res.end(); ++it)
		{
			re = *it + ' ' + re;
		}
		re.pop_back();
		return re;
	}
};


int main()
{


	return 0;
}