// 面试题56 - II. 数组中数字出现的次数 II

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


class Solution {
public:
	int singleNumber1(vector<int>& nums) {
		map<int, int> m;
		for (auto &num : nums)
		{
			++m[num];
		}
		for (auto it = m.begin(); it != m.end(); ++it)
		{
			if (it->second == 1)
				return it->first;
		}
		return 0;
	}

	int singleNumber(vector<int>& nums) {
		int bit[32] = { 0 };
		for (int i = 0; i < nums.size(); ++i)
		{
			unsigned int bitmask = 1;
			for (int j = 31; j >= 0; --j)
			{
				int b = nums[i] & bitmask;
				if (b != 0)
					bit[j] += 1;
				bitmask = bitmask << 1;
			}
		}
		int res = 0;
		for (int i = 0; i < 32; ++i)
		{
			res = res << 1;
			res += bit[i] % 3;
		}
		return res;
	}
};



int main()
{

	std::cout << std::endl;
	return 0;
}