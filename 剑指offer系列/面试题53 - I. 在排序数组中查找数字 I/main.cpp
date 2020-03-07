// 面试题53 - I. 在排序数组中查找数字 I

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // 方法1
    int search1(vector<int>& nums, int target) {
        int re = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == target)
                ++re;
        }
        return re;
    }

    // 二分法
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return 0;

        int left = left_bound(nums, target);
        int right = right_bound(nums, target);
        if (left == -1 && right == -1)
            return 0;
        return right - left + 1;
    }

    int left_bound(vector<int> &nums, int target)
    {
        if (nums.empty()) return -1;
        int left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        if (left >= nums.size() || nums[left] != target)
            return -1;
        return left;
    }

    int right_bound(vector<int> &nums, int target)
    {
        if (nums.empty()) return -1;
        int left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        if (right < 0 || nums[right] != target)
            return -1;
        return right;
    }
};

int main() {
    vector<int> a = {5,7,7,8,8,10};
    cout << Solution().search(a, 6) << endl;

    std::cout << std::endl;
    return 0;
}
