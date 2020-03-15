// 面试题66. 构建乘积数组

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<int> constructArr(vector<int>& a) {
		if (a.empty())
			return a;

		vector<int> left(a.size());
		vector<int> right(a.size());

		int t = 1;
		for (int i = 0; i < a.size(); ++i)
		{
			left[i] = t;
			t *= a[i];
		}
		t = 1;
		for (int i = a.size() - 1; i >= 0; --i)
		{
			right[i] = t * left[i];
			t *= a[i];
		}
		return right;
	}
};

int main()
{
	vector<int> a = { 1,2,3,4,5 }, re;
	re = Solution().constructArr(a);

	std::cout << std::endl;
	return 0;
}