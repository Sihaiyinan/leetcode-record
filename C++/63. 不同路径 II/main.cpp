// 63. 不同路径 II

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 0;

        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        vector<long long> dp(col);

        int flag = 1;
        for (int i = 0; i < col; ++i)
        {
            dp[i] = flag;
            if (obstacleGrid[0][i] == 1)
            {
                flag = 0;
                dp[i] = 0;
            }
        }


        for (int i = 1; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (obstacleGrid[i][j] == 1)
                    dp[j] = 0;
                else if (i > 0 && j > 0 && obstacleGrid[i][j] == 0)
                {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp[col - 1];
    }
};


int main()
{

    return 0;
}
