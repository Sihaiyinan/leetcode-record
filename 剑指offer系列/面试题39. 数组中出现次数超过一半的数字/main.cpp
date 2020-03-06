// 面试题39. 数组中出现次数超过一半的数字

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // 方法1，基于partition函数，需要修改数组
    int majorityElement1(vector<int>& nums) {
        if (nums.empty()) return 0;

        int mid = nums.size() / 2;
        int begin = 0, end = nums.size() - 1;
        int index = partition(nums, begin, end);
        while (index != mid)
        {
            if (index < mid)
            {
                begin = index + 1;
                index = partition(nums, begin, end);
            } else
            {
                end = index - 1;
                index = partition(nums, begin, end);
            }
        }
        return nums[index];
    }

    int partition(vector<int> &nums, int begin, int end)
    {
        int val = nums[begin];
        while (begin < end)
        {
            while (begin < end && nums[end] >= val)
                --end;
            nums[begin] = nums[end];
            while (begin < end && nums[begin] <= val)
                ++begin;
            nums[end] = nums[begin];
        }
        nums[begin] = val;
        return begin;
    }

    // 方法2
    int majorityElement(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = nums[0];
        int times = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (times == 0)
            {
                res = nums[i];
                times = 1;
            } else if (nums[i] == res)
                ++times;
            else
                --times;
        }
        return res;
    }
    };

int main() {
    vector<int> a = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    int re = Solution().majorityElement(a);
    cout << re << endl;


    std::cout << std::endl;
    return 0;
}
