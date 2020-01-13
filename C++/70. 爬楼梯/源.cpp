#include<iostream>

using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		int a = 0, b = 1, re = 0;
		for (int i = 0; i < n; ++i)
		{
			re = a + b;
			a = b;
			b = re;
		}
		return re;
	}
};

int main()
{
	int n = 9;
	cout << Solution().climbStairs(n) << endl;
	return 0;
}