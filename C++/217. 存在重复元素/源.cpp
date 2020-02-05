#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		map<int, int> m;
		for (auto &i : nums)
		{
			if (m.find(i) != m.end())
				return true;
			m[i] = 1;
		}
		return false;
	}
};

int main() {
	vector<int> n = { 1,2,3,4 };
	cout << Solution().containsDuplicate(n);

	cout << endl;
	return 0;
}
