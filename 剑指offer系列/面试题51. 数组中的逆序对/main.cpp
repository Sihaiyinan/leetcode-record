// 面试题51. 数组中的逆序对

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int reversePairs(vector<int>& nums) {
		if (nums.empty())
			return 0;
		vector<int> copy = nums;
		int count = reversePairsCore(nums, copy, 0, nums.size() - 1);
		return count;
	}

	int reversePairsCore(vector<int> &nums, vector<int> &copy, int begin, int end)
	{
		if (begin == end)
		{
			copy[begin] == nums[begin];
			return 0;
		}
		int len = (end - begin) / 2;

		int left = reversePairsCore(copy, nums, begin, begin + len);
		int right = reversePairsCore(copy, nums, begin + len + 1, end);

		int i = begin + len;
		int j = end;
		int indexCopy = end;
		int count = 0;
		while (i >= begin && j >= begin + len + 1)
		{
			if (nums[i] > nums[j])
			{
				copy[indexCopy--] = nums[i--];
				count += j - begin - len;
			}
			else
				copy[indexCopy--] = nums[j--];
		}
		for (; i >= begin; --i)
			copy[indexCopy--] = nums[i];
		for (; j >= begin + len + 1; --j)
			copy[indexCopy--] = nums[j];
		return left + right + count;
	}
};

int main()
{

	std::cout << std::endl;
	return 0;
}