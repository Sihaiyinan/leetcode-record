// 面试题45. 把数组排成最小的数

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
	static bool compare(string a, string b)
	{
		string t = a;
		while (t.size() % b.size() != 0)
		{
			t += a;
		}
		string s = b;
		while (s.size() < t.size())
		{
			s += b;
		}
		return t < s;
	}

	string minNumber(vector<int>& nums) {
		if (nums.empty())
			return "";
		vector<string> s;
		for (auto &i : nums)
		{
			s.push_back(to_string(i));
		}
		sort(s.begin(), s.end(), compare);

		string re;
		for (auto i : s)
			re += i;

		return re;
	}
};


int main()
{
	vector<int> a = { 3,30,34,9,5 };
	string s = Solution().minNumber(a);

	std::cout << std::endl;
	return 0;
}