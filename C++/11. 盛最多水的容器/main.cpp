#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int len = height.size();
		int l = 0;
		int r = len - 1;
		int area = 0;

		while (r - l >= 1)
		{
			int t = (r - l) * min(height[l], height[r]);
			if (t > area) area = t;
			height[l] < height[r] ? l++ : r--;
		}
		return area;
	}
};

int main()
{
	vector<int> a = { 1,8,6,2,5,4,8,3,7 };
	cout << Solution().maxArea(a) << endl;
	return 0;
}