#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1[0] == '0' || num2[0] == '0')
			return string("0");

		int s1 = num1.size(), s2 = num2.size();
		vector<int> res(s1 * s2, 0);       // 创建一个数组保存计算结果

		for (int i = 0; i < s2; ++i)
			for (int j = 0; j < s1; ++j)
				res[i + j] += (num1[s1 - j - 1] - '0') * (num2[s2 - i - 1] - '0');

		// 处理多余的0
		while (res[res.size() - 1] == 0)
			res.pop_back();

		// 进位处理
		res.push_back(0);  // 多一个0方便最后一位大于9时进位
		for (int i = 0; i < res.size() - 1; ++i)
		{
			if (res[i] > 9)
			{
				res[i + 1] += res[i] / 10;
				res[i] %= 10;
			}
		}
		if (res[res.size() - 1] == 0) res.pop_back();    // 如果最后一位是0就去掉

		string re;
		for (int i = 0; i < res.size(); ++i)
		{
			re += res[res.size() - i - 1] + '0';
		}

		return re;
	}
};

int main() {
	string s1 = "123456789", s2 = "987654321", re;
	re = Solution().multiply(s1, s2);
	for (auto i : re)
		cout << i;
	cout << endl;
	return 0;
}
