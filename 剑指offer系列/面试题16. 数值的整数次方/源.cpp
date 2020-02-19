// 面试题13. 机器人的运动范围

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0)
			return 1;
		if (n < 0)
			return 1 / myPow(x, -n);
		if (n == 1)
			return x;
		double re = myPow(x, n >> 1);
		re *= re;
		if ((n & 0x1) == 1)
			re *= x;
		return re;
	}
};

int main() 
{
	double x = -2, n = -2;
	cout << Solution().myPow(x, n) << endl;


	std::cout << endl;
	return 0;
}
