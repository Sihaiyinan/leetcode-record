// 69. x 的平方根

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
	// 二分法
	int mySqrt1(int x) {
		if (x == 0) return 0;

		int l = 1, r = x;

		while (l <= r)
		{

			long long mid = l + (r - l) / 2;

			if (mid * mid == x)
				return (int)mid;
			else if (mid * mid > x)
				r = mid;
			else
			{
				if ((mid + 1) * (mid + 1) > x)
					return (int)mid;
				l = mid;
			}	
		}
		return 0;
	}

	// 数学法
	// x^0.5 = (e^(lnx))^0.5 = e^(0.5 * lnx)
	int mySqrt(int x)
	{
		if (x == 0) return 0;

		int res = exp(0.5 * log(x));
		return ((long long)(res + 1) * (res + 1) <= x ? res + 1 : res);
	}

	// 牛顿法
	int mySqrt2(int x)
	{
		if (x == 0) return 0;

		double C = x, x0 = x;
		while (true)
		{
			double xi = 0.5 * (x0 + C / x0);
			if (fabs(x0 - xi) < 1e-7)
			{
				break;
			}
			x0 = xi;
		}
		return (int)x0;
	}
};



int main()
{


	std::cout << std::endl;
	return 0;
}