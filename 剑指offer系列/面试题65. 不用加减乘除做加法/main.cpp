// 面试题65. 不用加减乘除做加法

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int add(int a, int b) {
		while (b != 0)
		{
			int t = a ^ b;
			b = (unsigned int) (a & b) << 1;
			a = t;
		}
		return a;
	}
};

int main()
{
	cout << Solution().add(-2, -3) << endl;
	std::cout << std::endl;
	return 0;
}