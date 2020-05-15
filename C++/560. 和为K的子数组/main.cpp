// 560. 和为K的子数组

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


class Solution {
public:
	// 暴力法
	int subarraySum1(vector<int>& nums, int k) {
		int res = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			int sum = 0;
			for (int j = i; j >= 0; --j)
			{
				sum += nums[j];
				if (sum == k)
					res += 1;
			}
		}
		return res;
	}

	// 哈希表
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		m[0] = 1;
		int c = 0, pre = 0;
		for (auto i : nums)
		{
			pre += i;
			if (m.find(pre - k) != m.end())
				c += m[pre - k];
			m[pre]++;
		}
		return c;
	}
};


int main()
{


	std::cout << std::endl;
	return 0;
}