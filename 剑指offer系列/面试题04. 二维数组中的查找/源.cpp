// 面试题04. 二维数组中的查找

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool findNumberIn2DArray1(vector<vector<int>>& matrix, int target) {
		if (matrix.empty()) return false;
		int row = matrix.size();
		int col = matrix[0].size();
		for (int i = col - 1; i >= 0; --i)
		{
			for (int j = 0; j < row; ++j)
			{
				if (target == matrix[j][i])
					return true;
				if (target < matrix[j][i])   // 在这里break之后j会重新等于0，需要优化
					break;
				if (target > matrix[j][i])
					continue;
			}
		}
		return false;
	}

	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		if (matrix.empty()) return false;
		int row = matrix.size();
		int col = matrix[0].size();
		int i = 0, j = col - 1;
		while (i < row && j >= 0)
		{
			if (matrix[i][j] == target)
				return true;
			else if (matrix[i][j] > target)
				--j;
			else
				++i;
		}
		return false;
	}
};

int main() 
{

	std::cout << endl;
	return 0;
}
