// 6. Z 字形变换

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)
			return s;

		int min_len = s.size() < numRows ? s.size() : numRows;
		vector<string> rows(min_len);
		int cur_row = 0;
		bool down = false;

		for (auto c : s)
		{
			rows[cur_row] += c;
			if (cur_row == 0 || cur_row == min_len - 1)
				down = !down;
			cur_row += down ? 1 : -1;
		}
		string res;
		for (auto i : rows)
			res += i;
		return res;
	}
};

int main()
{

	return 0;
}