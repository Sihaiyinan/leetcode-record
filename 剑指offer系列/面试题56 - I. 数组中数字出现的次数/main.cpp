// 面试题56 - I. 数组中数字出现的次数

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;


class Solution {
public:
	vector<int> singleNumbers1(vector<int>& nums) {
		vector<int> re;
		map<int, int> m;
		for (auto &num : nums)
		{
			++m[num];
		}
		for (auto it = m.begin(); it != m.end(); ++it)
		{
			if (it->second == 1)
				re.push_back(it->first);
		}
		return re;
	}

	// 位运算
	vector<int> singleNumbers(vector<int>& nums) {
		int xor = 0;
		vector<int> ans = { 0, 0 };   // 需要返回两位数，正好相当于0和1

		for (auto &num : nums)
			xor ^= num;        // 此时xor相当于是两个不同的数之间异或

		int low = xor ^ (xor -1) & xor;  // 找出两个数的二进制中不同的最低位
		for (auto &num : nums)
			ans[!(num & low)] ^= num;
		return ans;
	}

};




int main()
{
	vector<int> a = { 4,7,4,1 }, re;
	re = Solution().singleNumbers(a);


	std::cout << std::endl;
	return 0;
}