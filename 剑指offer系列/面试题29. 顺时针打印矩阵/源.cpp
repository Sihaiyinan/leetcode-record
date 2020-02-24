// 面试题29. 顺时针打印矩阵
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> re;
		if (matrix.empty()) return re;

		int rows = matrix.size();
		int cols = matrix[0].size();
		vector<int> visited(rows * cols);
		vector<pair<int, int>> move = { make_pair(0, 1), make_pair(1, 0), make_pair(0, -1), make_pair(-1, 0) };

		int row = 0, col = -1, move_ind = 0;
		while (re.size() < visited.size())
		{
			move_ind %= 4;
			row += move[move_ind].first;
			col += move[move_ind].second;
			if (row >= 0 && row < rows && col >= 0 && col < cols && !visited[row * cols + col])
			{
				visited[row * cols + col] = 1;
				re.push_back(matrix[row][col]);
			}
			else
			{
				row -= move[move_ind].first;
				col -= move[move_ind].second;
				++move_ind;
			}
				
		}
		return re;
	}
};

int main() 
{
	vector<vector<int>> m = { {1,2,3}, {4,5,6}, {7,8,9} };
	vector<int> re = Solution().spiralOrder(m);
	for (auto &i : re)
		cout << i << ' ';


	std::cout << endl;
	return 0;
}
