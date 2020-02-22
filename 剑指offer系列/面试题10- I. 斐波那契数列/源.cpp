// 面试题10- I. 斐波那契数列

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int fib(int n) {
		int a = 0, b = 1, re = 0;
		if (n == 0) return a;
		if (n == 1) return b;
		for (int i = 2; i <= n; ++i)
		{
			re = (a + b) % 1000000007;
			a = b;
			b = re;
		}
		return re;
	}
};

int main() 
{
	int f = 6;
	cout << Solution().fib(f) << endl;

	std::cout << endl;
	return 0;
}
