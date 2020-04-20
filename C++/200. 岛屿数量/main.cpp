// 200. 岛屿数量

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int row = grid.size();
        int col = grid[0].size();

        int res = 0;
        vector<vector<int>> move = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (grid[i][j] == '1')
                {
                    queue<vector<int>> q;
                    q.push({i, j});
                    grid[i][j] = '0';
                    while (!q.empty())
                    {
                        auto tmp = q.front();
                        q.pop();

                        for (auto mo : move)
                        {
                            int nx = tmp[0] + mo[0];
                            int ny = tmp[1] + mo[1];
                            if (nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == '1')
                            {
                                q.push({nx, ny});
                                grid[nx][ny] = '0';
                            }
                        }
                    }
                    res += 1;
                }
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}
