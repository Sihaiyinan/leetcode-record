// 面试题64. 求1+2+…+n

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
	int sumNums(int n) {
		n && (n += sumNums(n - 1));
		return n;
	}
};

int main()
{
	cout << Solution().sumNums(100) << endl;
	std::cout << std::endl;
	return 0;
}