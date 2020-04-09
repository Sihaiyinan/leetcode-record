// 18. 四数之和

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		if (nums.size()<4)
			return result;

		size_t n_size = nums.size();
		sort(nums.begin(), nums.end());

		for (int i = 0; i<n_size - 3; i++) {
			if (target <= 0 && nums[i]>0) break;
			if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3]>target) break;
			if (nums[i] + nums[n_size - 3] + nums[n_size - 2] + nums[n_size - 1]<target) continue;
			if (i>0 && nums[i] == nums[i - 1]) continue;

			for (int j = i + 1; j<n_size - 2; j++) {
				if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2]>target) break;
				if (nums[i] + nums[j] + nums[n_size - 2] + nums[n_size - 1]<target) continue;
				if (j>i + 1 && nums[j] == nums[j - 1]) continue;

				int start = j + 1, end = n_size - 1;
				while (start<end) {
					int sum = nums[i] + nums[j] + nums[start] + nums[end];
					if (sum<target) start++;
					else if (sum>target) end--;
					else {
						result.push_back({ nums[i], nums[j], nums[start], nums[end] });
						int last_start = start, last_end = end;
						while (start<end && nums[start] == nums[last_start]) start++;
						while (start<end && nums[end] == nums[last_end]) end--;
					}
				}
			}
		}
		return result;
	}
};


int main()
{


	return 0;
}