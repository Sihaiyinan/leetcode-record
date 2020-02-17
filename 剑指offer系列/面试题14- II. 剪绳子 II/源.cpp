// 面试题14- II. 剪绳子 II

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	// 贪心算法
	int cuttingRope(int n) {
		if (n <= 3) return n - 1;    // 当数小于3时不需要拆分

		int timeOf3 = n / 3;         // 计算可以拆分成3的次数
		if (n % 3 == 1)              // 计算拆分3之后的余数， 当余数等于1时，将3的次数减去1，然后将剩下的4分成2*2
			timeOf3 -= 1;
		int timeOf2 = (n - timeOf3 * 3) / 2;
		long long res = 1;
		while (timeOf3--)            // 会溢出，所以取余
		{
			res = res * 3 % 1000000007;
		}
		res = res * (int)pow(2, timeOf2) % 1000000007;
		return (int)res;
	}
};

int main() 
{
	int a = 4;
	cout << Solution().cuttingRope(a) << endl;
	std::cout << endl;
	return 0;
}
