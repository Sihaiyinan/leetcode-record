// 快速排序

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int partition(vector<int> &nums, int left, int right)
    {
        int val = nums[left];

        while (left < right)
        {
            while (left < right && nums[right] >= val)
            {
                --right;
            }
            nums[left] = nums[right];
            while (left < right && nums[left] <= val)
            {
                ++left;
            }
            nums[right] = nums[left];
        }
        nums[left] = val;
        return left;
    }

    int quickSortCore(vector<int> &nums, int l, int r)
    {
        if (l < r)
        {
            int pos = partition(nums, l, r);
            quickSortCore(nums, l, pos - 1);
            quickSortCore(nums, pos + 1, r);
        }
        return 0;
    }

    int quickSort(vector<int> &nums)
    {
        if (nums.size() < 2) return 0;

        quickSortCore(nums, 0, nums.size() - 1);
        return 0;
    }

};


int main()
{
    vector<int> nums = {3,5,4,6,8,2,1,9,7};
    Solution().quickSort(nums);

    for (auto &i : nums)
        cout << i << ' ';
    cout << endl;

    return 0;
}
