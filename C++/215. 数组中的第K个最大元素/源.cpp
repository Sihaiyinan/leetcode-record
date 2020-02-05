#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int compare(const void * a, const void * b)
{
	return (*(int*)a - *(int*)b);
}

class Solution {
public:
	int findKthLargest1(vector<int>& nums, int k) {
		vector<int> heap;
		for (int i : nums)
		{
			heap.push_back(i);
			if (heap.size() > k)
			{
				auto it = min_element(heap.data(), heap.data() + heap.size());
				heap.erase(heap.begin() + (it - heap.data()));
			}
		}
		return *min_element(heap.data(), heap.data() + heap.size());
	}



	int findKthLargest(vector<int>& nums, int k) {
		qsort(nums.data(), nums.size(), sizeof(int), compare);
		return nums[nums.size() - k];
	}
};

int main() {
	vector<int> n = { 3,2,1,5,6,4 };
	cout << Solution().findKthLargest(n, 2);

	cout << endl;
	return 0;
}
