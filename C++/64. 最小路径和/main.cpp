// 64. 最小路径和

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int row = grid.size();
        int col = grid[0].size();

        vector<int> dp(col);

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (i == 0)
                {
                    if (j == 0)
                        dp[j] = grid[i][j];
                    else
                        dp[j] = dp[j - 1] + grid[i][j];
                } else
                {
                    if (j == 0)
                        dp[j] += grid[i][j];
                    else
                        dp[j] = min(dp[j - 1], dp[j]) + grid[i][j];
                }
            }
        }
        return dp[col - 1];
    }
};


int main()
{
    vector<vector<int>> a = {{1,3,1}, {1,5,1}, {4,2,1}};
    cout << Solution().minPathSum(a) << endl;
    return 0;
}
