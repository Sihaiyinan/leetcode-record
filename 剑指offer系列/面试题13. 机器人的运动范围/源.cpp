// 面试题13. 机器人的运动范围

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
	int movingCount(int m, int n, int k) {
		if (k < 0 || m <= 0 || n <= 0)
			return 0;
		vector<int> visited(m * n);    // 记录该位置是否已经经过

		int count = movingCountCore(k, 0, 0, m, n, visited);       // 从（0,0）开始进行回溯
		return count;
	}

	int movingCountCore(int threshold, int row, int col, int rows, int cols, vector<int> &visited)
	{
		int count = 0;
		if (check(threshold, row, col, rows, cols, visited))  // 用check函数检查是否满足题目要求条件
		{
			visited[row * cols + col] = 1;
			count = 1 + movingCountCore(threshold, row - 1, col, rows, cols, visited)      // 计算该位置的四个方向满足条件的个数
				+ movingCountCore(threshold, row + 1, col, rows, cols, visited)
				+ movingCountCore(threshold, row, col - 1, rows, cols, visited)
				+ movingCountCore(threshold, row, col + 1, rows, cols, visited);
		}
		return count;
	}

	bool check(int threshold, int row, int col, int rows, int cols, vector<int> &visited)
	{
		if (row >= 0 && row < rows && col >= 0 && col < cols
			&& (getDigitSum(row) + getDigitSum(col) <= threshold)
			&& !visited[row * cols + col])
			return true;
		return false;
	}

	int getDigitSum(int n)
	{
		int s = 0;
		while (n > 0)
		{
			s += n % 10;
			n /= 10;
		}
		return s;
	}

	// bfs
	int movingCount1(int m, int n, int k) {
		if (m <= 0 || n <= 0 || k < 0)
			return 0;
		
		vector<vector<int>> move = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };    // 当前位置的四个方向
		int count = 1;            // 初始计数为1
		queue<vector<int>> q;     // 创建一个队列用来保存走过的位置
		q.push({ 0, 0 });         // 初始位置为（0,0）

		vector<int> visited(m * n);   
		visited[0] = 1;

		while (!q.empty())        // 当队列不为空时说明存在满足条件的位置，需要对该位置周围的四个位置进行判断
		{
			int x = q.front()[0];
			int y = q.front()[1];
			q.pop();     // 当当前位置弹出
			
			for (auto &i : move)    // 依次对四个方向进行判断
			{
				int nx = x + i[0]; 
				int ny = y + i[1];
				
				// 判断是否越界、满足题目要求、该位置是否访问过
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && (getDigitSum(nx) + getDigitSum(ny) <= k && !visited[ny * n + nx]))
				{
					++count;
					visited[ny * n + nx] = 1;
					q.push({ nx, ny });       // 将满足要求的位置加入到队列中
				}
			}
		}
		return count;
	}
};

int main() 
{
	int m = 2, n = 3, k = 1;
	cout << Solution().movingCount1(m, n, k) << endl;



	std::cout << endl;
	return 0;
}
