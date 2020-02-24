// 面试题22. 链表中倒数第k个节点

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	// 超时
	vector<int> exchange1(vector<int>& nums) {
		if (nums.empty()) return nums;

		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] % 2 == 0)
			{
				for (int j = i; j < nums.size(); ++j)
				{
					if (nums[j] % 2 == 1)
					{
						int tmp = nums[j];
						nums[j] = nums[i];
						nums[i] = tmp;
						break;
					}
				}
			}
		}
		return nums;
	}

	vector<int> exchange(vector<int>& nums) {
		if (nums.empty()) return nums;
		int begin = 0, end = nums.size() - 1;
		while (begin < end)
		{
			while (begin < end && ((nums[begin] & 0x1) == 1))
				++begin;
			while (begin < end && ((nums[end] & 0x1) == 0))
				--end;

			if (begin < end)
			{
				int tmp = nums[begin];
				nums[begin] = nums[end];
				nums[end] = tmp;
			}
		}
		return nums;
	}
};

int main() 
{
	vector<int> a = { 1,2,3,4 }, re;
	re = Solution().exchange(a);
	for (auto &i : re)
		cout << i << ' ';

	std::cout << endl;
	return 0;
}
