// 62. 不同路径

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		if (m < 1 || n < 1) return -1;
		vector<int> dp(n, 1);
		for (int i = 1; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (j == 0) dp[j] = 1;
				else
				{
					dp[j] += dp[j - 1];
				}
			}
		}
		return dp[n - 1];
	}
};

int main()
{


	return 0;
}