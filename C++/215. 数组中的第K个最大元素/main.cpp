// 215. 数组中的第K个最大元素

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <ctime>


using namespace std;

class Solution {
public:
    // 方法一 sort排序
    int findKthLargest1(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return *(nums.end() - k);
    }

    // 方法二 优先队列 大顶堆
    int findKthLargest2(vector<int>& nums, int k) {
        priority_queue<int> q;
        for (auto &i : nums)
        {
            q.push(i);
        }

        while (--k)
        {
            q.pop();
        }
        return q.top();
    }

    // 方法三
    int findKthLargest3(vector<int>& nums, int k) {
        vector<int> heap;
        for (int i : nums)
        {
            heap.push_back(i);
            if (heap.size() > k)
            {
                auto it = min_element(heap.data(), heap.data() + heap.size());
                heap.erase(heap.begin() + (it - heap.data()));
            }
        }
        return *min_element(heap.data(), heap.data() + heap.size());
    }


    // 方法四 快速选择
    int quickSelect(vector<int> &nums, int l, int r, int index)
    {
        int q = qsortCore(nums, l, r);
        if (q == index)
            return nums[q];
        else
            return q < index ? quickSelect(nums, q + 1, r, index) : quickSelect(nums, l, q - 1, index);
    }

    int qsortCore(vector<int> &nums, int l, int r)
    {
        int i = rand() % (r - l + 1) + l;
        swap(nums[i], nums[r]);
        return partition(nums, l, r);
    }

    int partition(vector<int> &nums, int l, int r)
    {
        int x = nums[r], i = l - 1;
        for (int j = l; j < r; ++j)
        {
            if (nums[j] <= x) swap(nums[j], nums[++i]);
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }

    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};

int main()
{
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    cout << Solution().findKthLargest(nums, 4) << endl;

    return 0;
}