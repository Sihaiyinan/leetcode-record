#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void huisu(vector<int> sub_nums, vector<int> cur_res, vector<vector<int>> &re)
	{
		if (sub_nums.size() == 0)
		{
			re.push_back(cur_res);
			return;
		}
		for (int i = 0; i < sub_nums.size(); ++i)
		{
			cur_res.push_back(sub_nums[i]);
			huisu(remove_num(sub_nums, i), cur_res, re);
			cur_res.pop_back();
		}
	}

	inline vector<int>remove_num(vector<int> nums, int i) 
	{ 
		nums.erase(nums.begin() + i); 
		return nums;
	}

	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> re;
		if (nums.empty()) { re.push_back({}); return re; }
		vector<int> res;
		huisu(nums, res, re);
		return re;
	}
};

int main() {
	vector<int> nums = { 1,2,3 };
	vector<vector<int>> re = Solution().permute(nums);
	for (auto &i : re)
	{
		for (auto &j : i)
		{
			cout << j;
		}
		cout << endl;
	}

	cout << endl;
	return 0;
}
