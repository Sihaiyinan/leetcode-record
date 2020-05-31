// 40. 组合总和 II

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

class Solution {
public:
    int nums = 0;
    vector<vector<int>> res;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        nums = target;

        vector<int> re;
        dfs(candidates, 0, re, 0);
        return res;
    }

    int dfs(vector<int> candidates, int sum, vector<int> &re, int idx)
    {
        // 当 sum == nums时，将符合要求的re加入到res中， 返回0
        if (sum == nums)
        {
            res.push_back(re);
            return 0;
        }
        // 当 sum > nums 时，返回0
        if (sum > nums)
        {
            return 0;
        }
        // i 从idx开始，防止结果重复
        for (int i = idx; i < candidates.size(); ++i)
        {
            if (i > idx && candidates[i] == candidates[i - 1]) continue;  // 去重
            re.push_back(candidates[i]);
            int f = dfs(candidates, sum + candidates[i], re, i + 1);
            re.pop_back();
            if (f == 0) break;   // 当返回的结果为0时，说明剩下的元素之和结果肯定大于target，因此直接跳出循环
        }
        return 1;
    }
};

int main()
{

    return 0;
}