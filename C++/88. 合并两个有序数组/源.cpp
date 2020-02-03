#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int> nums1_copy;
		for (int i = 0; i < m; ++i)
			nums1_copy.push_back(nums1[i]);
		nums1.clear();
		
		int p1 = 0, p2 = 0;
		while (p1 < m && p2 < n)
		{
			if (nums1_copy[p1] < nums2[p2])
			{
				nums1.push_back(nums1_copy[p1]);
				++p1;
			}
			else
			{
				nums1.push_back(nums2[p2]);
				++p2;
			}
		}
		while (p1 < m)
		{
			nums1.push_back(nums1_copy[p1]);
			++p1;
		}
		while (p2 < n)
		{
			nums1.push_back(nums2[p2]);
			++p2;
		}
	}


	void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int p = m + n - 1, p1 = m - 1, p2 = n - 1;

		while (p1 >= 0 && p2 >= 0)
		{
			if (nums1[p1] > nums2[p2])
			{
				nums1[p] = nums1[p1];
				--p1;
			}
			else
			{
				nums1[p] = nums2[p2];
				--p2;
			}
			--p;
		}
		for (int i = 0; i < p2 + 1; ++i)
			nums1[i] = nums2[i];
	}

};

int main() {
	vector<int> nums1 = { 1,2,3,0,0,0 };
	vector<int> nums2 = { 2,5,6 };
	Solution().merge1(nums1, 3, nums2, 3);
	for (auto i : nums1)
	{
		cout << i;
	}


	cout << endl;
	return 0;
}
