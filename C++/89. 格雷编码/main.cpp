// 89. 格雷编码

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> res = { 0 };
		int t = 1;

		for (int i = 0; i < n; ++i)
		{
			for (int j = res.size() - 1; j >= 0; --j)
			{
				res.push_back(t + res[j]);
			}
			t <<= 1;
		}
		return res;
	}
};

int main()
{

	return 0;
}