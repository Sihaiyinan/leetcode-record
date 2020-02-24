// 面试题31. 栈的压入、弹出序列
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		if (pushed.empty() && popped.empty())
			return true;
		if (pushed.empty() || popped.empty())
			return false;

		vector<int> s;    // 辅助栈
		int j = 0;        // popped下标
		for (auto i : pushed)
		{
			s.push_back(i);
			while (!s.empty() && popped[j] == s[s.size() - 1])
			{
				s.pop_back();
				++j;
			}
		}
		return s.empty();
	}
};


int main() 
{
	vector<int> pushed = { 1,2,3,4,5 };
	vector<int> popped = { 4,5,3,2,1 };
	cout << Solution().validateStackSequences(pushed, popped) << endl;

	std::cout << endl;
	return 0;
}
