// 面试题47. 礼物的最大价值

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // 方法1，超时
    int maxValue1(vector<vector<int>>& grid) {
        int re = 0;
        if (grid.empty()) return re;

        int h = grid.size();
        int w = grid[0].size();

        return maxValueCore(grid, 0, 0, h, w);
    }

    int maxValueCore(vector<vector<int>> &grid, int i, int j, int h, int w)
    {
        int right = 0, down = 0;
        if ((i + 1) > 0 && (i + 1) < h)
            down = maxValueCore(grid, i + 1, j, h, w);
        if ((j + 1) > 0 && (j + 1) < w)
            right = maxValueCore(grid, i, j + 1, h, w);
        return max(right, down) + grid[i][j];
    }

    // 方法2 dp
    int maxValue2(vector<vector<int>>& grid) {
        int re = 0;
        if (grid.empty()) return re;

        int h = grid.size();
        int w = grid[0].size();

        vector<vector<int>> dp;
        for (int i = 0; i < h; ++i)
            dp.push_back(vector<int>(w));

        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                int left = 0, up = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = max(up, left) + grid[i][j];
            }
        }
        return dp[h - 1][w - 1];
    }

    // 方法3，dp
    int maxValue(vector<vector<int>>& grid) {
        int re = 0;
        if (grid.empty()) return re;

        int h = grid.size();
        int w = grid[0].size();

        vector<int> dp(w);
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                int left = 0, up = 0;
                if (i > 0)
                    up = dp[j];
                if (j > 0)
                    left = dp[j - 1];
                dp[j] = max(up, left) + grid[i][j];
            }
        }
        return dp[w - 1];
    }

};


int main() {
    vector<vector<int>> grid = {{1,3,1}, {1,5,1}};
    int re = Solution().maxValue(grid);
    cout << re << endl;


    std::cout << std::endl;
    return 0;
}
