// 322. 零钱兑换

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		int Max = amount + 1;
		vector<int> dp(amount + 1, Max);
		dp[0] = 0;

		for (int i = 1; i <= amount; ++i)
		{
			for (auto c : coins)
			{
				if (c <= i)
					dp[i] = min(dp[i], dp[i - c] + 1);
			}
		}
		return dp[amount] > amount ? -1 : dp[amount];
	}
};


int main()
{
	int n = 10;

	return 0;
}