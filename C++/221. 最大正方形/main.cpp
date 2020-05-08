// 221. 最大正方形

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 暴力法 O(mn*min(m,n)^2)
    int maximalSquare1(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;

        int row = matrix.size();
        int col = matrix[0].size();


        int max_val = 0;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                int s = 1;
                if (matrix[i][j] == '1')
                {
                    int tmp = isSquare(matrix, i, j, s, row, col);
                    max_val = max(max_val, tmp);
                }
            }
        }
        return max_val * max_val;
    }

    int isSquare(vector<vector<char>>& matrix, int x, int y, int &s, int row, int col)
    {
        if (x + s < row && y + s < col)
        {
            int nx = x + s;
            int ny = y + s;

            for (int i = y; i <= ny; ++i)
            {
                if (matrix[nx][i] != '1')
                    return s;
            }
            for (int i = x; i <= nx; ++i)
            {
                if (matrix[i][ny] != '1')
                    return s;
            }

            s += 1;
            return isSquare(matrix, x, y, s, row, col);
        }
        return s;
    }

    // 方法2 动态规划
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;

        int row = matrix.size();
        int col = matrix[0].size();

        int dp[row][col];
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                dp[i][j] = 0;
            }
        }

        int max_val = 0;
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    if (i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                }
                max_val = max(max_val, dp[i][j]);
            }
        }
        return max_val * max_val;
    }

};



int main()
{
    vector<vector<char>> a = {{'1', '1'}, {'1', '1'}};
    Solution().maximalSquare(a);

    return 0;
}