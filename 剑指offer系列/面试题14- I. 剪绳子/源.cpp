// 面试题14- I. 剪绳子

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int cuttingRope(int n) {
		if (n < 2) return 0;
		if (n == 2) return 1;
		if (n == 3) return 2;

		vector<int> re = { 0, 1, 2, 3 };
		for (int i = 4; i <= n; ++i)
		{
			int max = 0;
			for (int j = 1; j <= i / 2; ++j)
			{
				int tmp = re[j] * re[i - j];
				if (tmp > max)
					max = tmp;
			}
			re.push_back(max);
		}
		return re.back();
	}
};


int main() 
{
	int a = 12;
	cout << Solution().cuttingRope(a) << endl;
	std::cout << endl;
	return 0;
}
