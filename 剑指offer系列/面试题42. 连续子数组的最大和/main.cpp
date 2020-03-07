// 面试题42. 连续子数组的最大和

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    // 方法1
    int maxSubArray1(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxc = 0x80000000;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (sum < 0)
                sum = nums[i];
            else
                sum += nums[i];
            if (sum > maxc)
                maxc = sum;
        }
        return maxc;
    }

    // 方法2 dp
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

int main() {
    vector<int> a = {-2,1,-3,4,-1,2,1,-5,4};
    cout << Solution().maxSubArray(a) << endl;


    std::cout << std::endl;
    return 0;
}
