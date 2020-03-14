// 面试题61. 扑克牌中的顺子

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool isStraight(vector<int>& nums) {
		int zero = 0;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 1; ++i)
		{
			if (nums[i] == 0) { zero++; continue; }
			if (nums[i] == nums[i + 1]) return false;
			if (nums[i] != nums[i + 1] + 1)zero -= nums[i + 1] - nums[i] - 1;
		}
		return zero >= 0;
	}
};


int main()
{

	std::cout << std::endl;
	return 0;
}