// 最小的K个数

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <ctime>


using namespace std;


class Solution {
public:

    // 方法一，sort排序
    vector<int> getLeastNumbers1(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());

        vector<int> res(k);
        for (int i = 0; i < k; ++i)
        {
            res[i] = arr[i];
        }
        return res;
    }

    // 方法二，大根堆
    vector<int> getLeastNumbers2(vector<int>& arr, int k) {
        vector<int> res(k);

        priority_queue<int> q;    // C++默认大根堆
//        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < k; ++i) q.push(arr[i]);
        for (int i = k; i < arr.size(); ++i)
        {
            if (arr[i] < q.top())
            {
                q.pop();
                q.push(arr[i]);
            }

        }

        for (int i = 1; i <= k; ++i)
        {
            res[k - i] = q.top();
            q.pop();
        }
        return res;
    }

    // 方法三，快排思想
    int partition(vector<int> &nums, int l, int r)
    {
        int val = nums[l];
        while (l < r)
        {
            while (l < r && nums[r] >= val) --r;
            nums[l] = nums[r];
            while (l < r && nums[l] <= val) ++l;
            nums[r] == nums[l];
        }
        nums[l] = val;
        return l;
    }

    int rand_partition(vector<int> &nums, int l, int r)
    {
        int i = rand() % (r - l + 1) + 1;
        swap(nums[l], nums[i]);
        return partition(nums, l, r);
    }

    int rand_selected(vector<int> &nums, int l, int r, int k)
    {
        if (l >= r) return 0;
        int pos = rand_partition(nums, l, r);
        int num = pos - l + 1;
        if (k == num) return 0;
        else if (k < num) rand_selected(nums, l, pos - 1, k);
        else rand_selected(nums, pos + 1, r, k - num);
    }

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        srand((unsigned) time(NULL));
        rand_selected(arr, 0, arr.size() - 1, k);
        vector<int> res;
        for (int i = 0; i < k; ++i) res.push_back(arr[i]);
        return res;
    }
};

int main()
{
    vector<int> nums = {3,6,2,8,5,1,7,9,4};
    auto res = Solution().getLeastNumbers(nums, 4);

    for (auto i : res) cout << i << ' ';
    
    return 0;
}



