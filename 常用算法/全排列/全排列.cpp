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


	// 方法2
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

	/*

	next_permutation(beg, end)
	next_permutation(beg, end, comp)
	如果序列已经是最后一个排列，则next_permutation将序列重排为最小排列，并返回false。
	否则，它将输入序列转换为字典序中的下一个排列，并返回true。


	prev_permutation(beg, end)
	prev_permutation(beg, end, comp)
	类似于next_permutation，但是将序列转换为前一个排列。如果序列已经是最小的排列，
	则将其重排为最大的排列，并返回false。

	*/


	// STL
	vector<vector<int>> permute1(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		do {
			res.push_back(nums);
		} while (next_permutation(nums.begin(), nums.end()));
		return res;
	}
};

int main()
{
	vector<int> nums = { 1,2,3 };
	auto res = Solution().permute1(nums);

	for (auto i : res)
	{
		for (auto j : i)
			cout << j << ' ';
		cout << endl;
	}


	return 0;
}