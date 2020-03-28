// 59. 螺旋矩阵 II

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res, move;
		move = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
		for (int i = 0; i < n; ++i)
		{
			vector<int> t(n);
			res.push_back(t);
		}

		int i = 0, j = -1, c = 1, mi = 0;
		while (c <= n*n)
		{
			auto m = move[mi % 4];
			i = i + m[0];
			j = j + m[1];
			if (i >= 0 && i < n && j >= 0 && j < n && res[i][j] == 0)
			{
				res[i][j] = c;
				++c;
			}
			else
			{
				i -= m[0];
				j -= m[1];
				++mi;
			}
		}
		return res;
	}
};

int main()
{


	return 0;
}