// 归并排序

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mergeSortCore(vector<int> &nums, vector<int> &copy, int left, int right)
    {
        if (left >= right) return 0;

        int mid = left + (right - left) / 2;
        mergeSortCore(copy, nums, left, mid);
        mergeSortCore(copy, nums, mid + 1, right);

        int i = left, j = mid + 1;
        int ind = left;

        while (i <= mid && j <= right)
        {
            if (nums[i] <= nums[j])
            {
                copy[ind] = nums[i];
                ++i;
            } else
            {
                copy[ind] = nums[j];
                ++j;
            }
            ++ind;
        }

        for (int k = i; k <= mid; ++k)
            copy[ind++] = nums[k];

        for (int k = j; k <= right; ++k)
            copy[ind++] = nums[k];

        return 0;
    }

    int mergeSort(vector<int>& nums) {
        vector<int> copy = nums;
        mergeSortCore(copy, nums, 0, nums.size() - 1);
        return 0;
    }
};


int main()
{
    vector<int> nums = {3,5,4,6,8,2,1,9,7};
    Solution().mergeSort(nums);

    for (auto &i : nums)
        cout << i << ' ';
    cout << endl;

    return 0;
}
