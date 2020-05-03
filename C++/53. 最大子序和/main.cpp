// 53. 最大子序和

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;

        // dp[i] = max(dp[i - 1] + nums[i], nums[i])
        int dp = nums[0];
        int re = dp;
        for (int i = 1; i < nums.size(); ++i)
        {
            dp = max(dp + nums[i], nums[i]);
            re = max(re, dp);
        }
        return re;
    }
};

int main()
{


	std::cout << std::endl;
	return 0;
}