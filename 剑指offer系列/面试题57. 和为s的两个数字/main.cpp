// 面试题57. 和为s的两个数字

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> re;
        if (nums.empty()) return re;

        int begin = 0, end = nums.size() - 1;
        while (begin < end)
        {
            while (begin < end && (nums[begin] + nums[end]) > target)
                --end;
            if ((nums[begin] + nums[end]) == target)
            {
                re.push_back(nums[begin]);
                re.push_back(nums[end]);
                break;
            }
            while (begin < end && (nums[begin] + nums[end]) < target)
                ++begin;
            if ((nums[begin] + nums[end]) == target)
            {
                re.push_back(nums[begin]);
                re.push_back(nums[end]);
                break;
            }
        }
        return re;
    }
};

int main() {
    vector<int> a = {2,7,11,15},re;
    re = Solution().twoSum(a, 9);

    std::cout << std::endl;
    return 0;
}
