// 面试题03. 数组中重复的数字

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		for (int i = 0; i < nums.size(); ++i)
		{
			while (i != nums[i])
			{
				if (nums[i] == nums[nums[i]])
					return nums[i];
				int t = nums[i];
				nums[i] = nums[t];
				nums[t] = t;
			}
		}
	}
};

int main() 
{
	vector<int> l = { 2, 3, 1, 0, 2, 5, 3 };
	cout << Solution().findRepeatNumber(l) << endl;

	std::cout << endl;
	return 0;
}
