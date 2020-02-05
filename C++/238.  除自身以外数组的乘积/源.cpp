#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int len = nums.size();
		vector<int> L(len), R(len), re(len);

		L[0] = 1;
		for (int i = 1; i < len; ++i)
			L[i] = L[i - 1] * nums[i - 1];

		R[len - 1] = 1;
		for (int i = len - 2; i >= 0; --i)
			R[i] = R[i + 1] * nums[i + 1];

		for (int i = 0; i < len; ++i)
			re[i] = L[i] * R[i];

		return re;
	}
};

int main() {
	vector<int> n = { 1,2,3,4 }, res;
	res = Solution().productExceptSelf(n);
	for (auto i : res)
		cout << i << ' ';

	cout << endl;
	return 0;
}
