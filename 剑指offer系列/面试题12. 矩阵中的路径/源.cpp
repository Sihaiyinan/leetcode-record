// 面试题12. 矩阵中的路径

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool hasPath(
		vector<vector<char>>& board, string &str, int &str_len,
		int i, int j, int &rows, int &cols, vector<int> &visited)
	{
		if (str_len == str.size())    // 如果str中的元素都比较完了，说明存在一条路径，返回true
			return true;
		
		bool isPath = false;
		if (i >= 0 && i < rows && j >= 0 && j < cols &&              // 判断是否超界
			board[i][j] == str[str_len] && !visited[i*cols + j])     // 判断该位置是否与str中的字符相等，判断该位置是否经过
		{
			++str_len;
			visited[i*cols + j] = 1;
			isPath = hasPath(board, str, str_len, i, j - 1, rows, cols, visited)    // 对四个方向进行判断
				|| hasPath(board, str, str_len, i, j + 1, rows, cols, visited)
				|| hasPath(board, str, str_len, i - 1, j, rows, cols, visited)
				|| hasPath(board, str, str_len, i + 1, j, rows, cols, visited);
			if (!isPath)     // 如果四个方向都不存在路径，说明该位置不存在路径，需要退回
			{
				--str_len;
				visited[i*cols + j] = 0;
			}
		}
		return isPath;
	}

	bool exist(vector<vector<char>>& board, string word) {
		if (word.empty()) return true;
		int rows = board.size();
		int cols = board[0].size();
		vector<int> flag(rows * cols);      // 判断该位置是否已经经过

		int str_len = 0;       // 当前位置在str中的长度
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				if (hasPath(board, word, str_len, i, j, rows, cols, flag))
					return true;
			}
		}
		return false;
	}
};

int main() 
{
	vector<vector<char>> a = { {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} };
	string word = "ABCCEEFFF";
	cout << Solution().exist(a, word) << endl;


	std::cout << endl;
	return 0;
}
