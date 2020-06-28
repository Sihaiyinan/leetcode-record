// 209. 长度最小的子数组

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>


using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;

        int l = 0, r = 0, res = 0, len = INT_MAX;
        while (r < nums.size())
        {
            res += nums[r];
            while (res >= s)
            {
                len = min(len, r - l + 1);
                res -= nums[l];
                ++l;
            }
            ++r;
        }
        return len == INT_MAX ? 0 : len;
    }
};

int main()
{
    vector<int> nums = {2,3,1,2,4,3};
    int s = 7;
    cout << Solution().minSubArrayLen(s, nums) << endl;

    return 0;
}