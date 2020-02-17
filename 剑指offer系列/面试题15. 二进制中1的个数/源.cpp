// 面试题15. 二进制中1的个数

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int hammingWeight1(uint32_t n) {
		unsigned int a = 1;
		int count = 0;
		while (a)
		{
			if (n & a)
				++count;
			a = a << 1;
		}
		return count;
	}

	// 一个数减去1后和它本身进行与运算，相当于把这个数最右边的1变成0；
	int hammingWeight(uint32_t n) {
		int count = 0;
		while (n)
		{
			++count;
			n = n & (n - 1);
		}
		return count;
	}


};

int main() 
{
	int a = 8;
	cout << Solution().hammingWeight(a) << endl;
	std::cout << endl;
	return 0;
}
