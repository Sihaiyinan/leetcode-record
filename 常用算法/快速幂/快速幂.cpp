﻿// 快速幂

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
	double myPow(double x, int n) {
		double res = 1.0;
		for (int i = n; i != 0; i /= 2)
		{
			if (i % 2 != 0)
				res *= x;
			x *= x;
		}
		return n < 0 ? 1 / res : res;
	}
};


int main()
{
	double x = 2;
	int n = 5;
	cout << Solution().myPow(x, n) << endl;

	std::cout << std::endl;
	return 0;
}