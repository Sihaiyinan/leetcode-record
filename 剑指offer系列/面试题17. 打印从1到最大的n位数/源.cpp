// 面试题17. 打印从1到最大的n位数

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
	vector<int> printNumbers(int n) {
		int number = 1;
		int i = 0;
		while (i++ < n)
			number *= 10;
		
		vector<int> re;
		for (int j = 1; j < number; ++j)
		{
			re.push_back(j);
		}
		return re;
	}
};

int main() 
{
	int n = 4;
	vector<int> re = Solution().printNumbers(n);
	for (auto &i : re)
		cout << i << ' ';


	std::cout << endl;
	return 0;
}
