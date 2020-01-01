#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int removeDuplicates1(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		int j = 0;
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[j] != nums[i])
				nums[++j] = nums[i];
		}
		++j;
		// nums.erase(nums.begin() + j, nums.end());
		return j;
	}

	int removeDuplicates(vector<int>& nums) {
		for (int i = 1; i < nums.size(); ++i)
		{
			if (nums[i] == nums[i - 1]) {
				nums.erase(nums.begin() + i);
				i--;
			}
		}
		return nums.size();
	}
};


int main()
{
	vector<int> a = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	int re = Solution().removeDuplicates1(a);
	cout << re << endl;
	for (int i : a) cout << i << ' ';
	cout << endl;
	return 0;
}