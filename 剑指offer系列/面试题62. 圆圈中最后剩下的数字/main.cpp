// 面试题62. 圆圈中最后剩下的数字

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int lastRemaining(int n, int m) {
		int last = 0;
		for (int i = 2; i <= n; ++i)
		{
			last = (last + m) % i;
		}
		return last;
	}
};

int main()
{
	cout << Solution().lastRemaining(5, 3) << endl;

	std::cout << std::endl;
	return 0;
}