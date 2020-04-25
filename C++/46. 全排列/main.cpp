// 全排列

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 方法1
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) { res.push_back({}); return res; }

        bianli(nums, 0, res);
        return res;
    }

    void bianli(vector<int> &nums, int ind, vector<vector<int>> &res)
    {
        if (ind == nums.size())
        {
            res.push_back(nums);
            return;
        }

        for (int i = ind; i < nums.size(); ++i)
        {
            swap(nums[ind], nums[i]);
            bianli(nums, ind + 1, res);
            swap(nums[ind], nums[i]);
        }
    }

    // STL
    vector<vector<int>> permute1(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        do {
            res.push_back(nums);
        }while (next_permutation(nums.begin(), nums.end()));
        return res;
    }

    // 方法3
    vector<vector<int>> permute2(vector<int> &nums)
    {
        vector<vector<int>> res;
        if (nums.empty()) { res.push_back({}); return res; }

        vector<int> used(nums.size(), 0), re;

        dfs(nums, 0, res, re, used);
        return res;
    }

    void dfs(vector<int> &nums, int ind, vector<vector<int>> &res, vector<int> &re, vector<int> &used)
    {
        if (ind == nums.size())
        {
            res.push_back(re);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (!used[i])
            {
                re.push_back(nums[i]);
                used[i] = 1;
                dfs(nums, ind + 1, res, re, used);
                used[i] = 0;
                re.pop_back();
            }
        }
    }
};

int main()
{
    vector<int> a = {1,2,3};
    auto res = Solution().permute2(a);


    return 0;
}
