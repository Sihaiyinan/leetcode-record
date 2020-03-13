// 面试题59 - I. 滑动窗口的最大值

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (nums.empty())
			return nums;
		vector<int> re;
		int left = 0;
		int right = k;
		while (right <= nums.size())
		{
			int tmp = *max_element(nums.begin() + left, nums.begin() + right);
			re.push_back(tmp);
			++left;
			++right;
		}
		return re;
	}
};

int main()
{
	vector<int> a = { 2,2,1,1,1,2,2 };


	std::cout << std::endl;
	return 0;
}