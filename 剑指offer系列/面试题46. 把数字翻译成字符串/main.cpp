// 面试题46. 把数字翻译成字符串

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
	// 回溯
	int translateNum(int num) {
		if (num < 10)
			return 1;
		int tmp = num % 100;
		if (tmp < 10 || tmp > 25)
			return translateNum(num / 10);
		else
			return translateNum(num / 10) + translateNum(num / 100);

	}
};


int main()
{
	vector<int> a = { 3,30,34,9,5 };

	std::cout << std::endl;
	return 0;
}