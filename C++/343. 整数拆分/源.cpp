// 343. 整数拆分

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n - 1;   // 当数小于3时不需要拆分

		int timesOf3 = n / 3;       // 计算可以拆分成3的次数
		int b = n % 3;       // 计算拆分3之后的余数， 当余数等于1时，将3的次数减去1，然后将剩下的4分成2*2

		if (b == 1)
			return (int)(pow(3, timesOf3 - 1) * 4);
		if (b == 0)
			return (int)(pow(3, timesOf3));
		return (int)pow(3, timesOf3) * 2;
    }
};


int main()
{



	return 0;
}