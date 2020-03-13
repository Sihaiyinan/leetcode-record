// 面试题60. n个骰子的点数

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<double> twoSum(int n) {
		double base = 1.0 / 6.0;
		vector<int> re(6 * n + 1, 0.0);
		for (int i = 1; i <= 6; ++i)
			re[i] = base;
		for (int i = 2; i <= n; ++i)
			for (int j = 6 * i; j >= i; --j)
			{
				re[j] = 0;
				for (int k = j - 1; k >= i - 1 && k >= j - 6; --k)
					re[j] += (re[k] * base);
			}
		return vector<double>(re.begin() + n, re.end());
	}
};

int main()
{
	vector<int> a = { 2,2,1,1,1,2,2 };


	std::cout << std::endl;
	return 0;
}