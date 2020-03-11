// 面试题46. 把数字翻译成字符串

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
	// 回溯
	int translateNum1(int num) {
		if (num < 10)
			return 1;
		int tmp = num % 100;
		if (tmp < 10 || tmp > 25)
			return translateNum(num / 10);
		else
			return translateNum(num / 10) + translateNum(num / 100);

	}

	//dp
	int translateNum(int num) {
		if (num < 0)
			return -1;
		string s = to_string(num);
		int dp[11];
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 1; i < s.size(); ++i)
		{
			if (s[i - 1] == '0' || s.substr(i - 1, 2) > "25")
				dp[i + 1] = dp[i];
			else
				dp[i + 1] = dp[i] + dp[i - 1];
		}
		return dp[s.size()];
	}
};


int main()
{
	vector<int> a = { 3,30,34,9,5 };

	std::cout << std::endl;
	return 0;
}