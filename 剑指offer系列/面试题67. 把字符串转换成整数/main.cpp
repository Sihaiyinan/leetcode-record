// 面试题67. 把字符串转换成整数

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int strToInt(string str) {
		int begin = 0;
		long long res = 0;
		int flag = 1;

		while (str[begin] == ' ') { ++begin; }
		if (str[begin] == '-') { flag = -1; }
		if (str[begin] == '+' || str[begin] == '-')
			++begin;

		while (begin < str.size() && str[begin] >= '0' && str[begin] <= '9')
		{
			res = res * 10 + (str[begin] - '0');
			if (res > 0x7FFFFFFF && flag == 1)
				return 0x7FFFFFFF;
			if (res > (unsigned int)0x80000000 && flag == -1)
				return 0x80000000;
			++begin;
		}
		return res * flag;
	}
};

int main()
{
	string s = "-91283472332";
	cout << Solution().strToInt(s) << endl;


	std::cout << std::endl;
	return 0;
}