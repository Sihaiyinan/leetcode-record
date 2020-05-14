// 136. 只出现一次的数字

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
	int singleNumber(vector<int>& nums) {
		if (nums.empty()) return 0;

		int res = nums[0];
		for (int i = 1; i < nums.size(); ++i)
			res = res ^ nums[i];

		return res;
	}
};


int main()
{


	std::cout << std::endl;
	return 0;
}