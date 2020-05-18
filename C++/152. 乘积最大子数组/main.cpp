// 152. 乘积最大子数组

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 动态规划
    int maxProduct(vector<int>& nums) {
        int max_val = nums[0], min_val = nums[0], res = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            int maxv = max_val, minv = min_val;
            max_val = max(nums[i], max(nums[i] * maxv, nums[i] * minv));
            min_val = min(nums[i], min(nums[i] * maxv, nums[i] * minv));
            res = max(max_val, res);
        }
        return res;
    }
};

int main()
{

    return 0;
}