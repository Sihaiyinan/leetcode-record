// 122. 买卖股票的最佳时机 II

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty()) return 0;
		int dp_i_0 = 0, dp_i_1 = 0x80000000;
		for (auto i : prices)
		{
			int tmp = dp_i_0;
			dp_i_0 = max(dp_i_0, dp_i_1 + i);
			dp_i_1 = max(dp_i_1, tmp - i);
		}
		return dp_i_0;
	}
};

int main()
{

	return 0;
}