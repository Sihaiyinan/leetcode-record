// 面试题40. 最小的k个数

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int h = grid.size();
        int w = grid[0].size();

        if (!find_fresh(grid))  // 如果没发现新鲜水果返回0
            return 0;

        int count = -1;
        vector<pair<int, int>> fulan;   // 存放所有腐烂水果的位置
        find_fulan(grid, fulan);
        if (fulan.empty()) return -1;   // 如果没发现腐烂水果说明不可能腐烂

        vector<vector<int>> move = {{0,-1}, {0,1}, {-1,0}, {1,0}};

        while (!fulan.empty())
        {
            vector<pair<int, int>> tmp;  // 存放本次腐烂了的水果的位置
            for (auto &i : fulan)    // 依次遍历当前所有的腐烂水果
            {
                int x = i.first;
                int y = i.second;
                for (auto &m : move)   // 判断当前腐烂水果周围的情况
                {
                    int nx = x + m[0];
                    int ny = y + m[1];
                    if (nx >= 0 && nx < h && ny >= 0 && ny < w && grid[nx][ny] == 1)
                    {
                        grid[nx][ny] = 2;     // 将新鲜水果感染
                        tmp.push_back(make_pair(nx, ny));
                    }
                }
            }
            fulan = tmp;
            ++count;
        }
        if (find_fresh(grid))   // 判断是否还有新鲜水果
            return -1;
        return count;
    }

    void find_fulan(vector<vector<int>> &grid, vector<pair<int, int>> &pos)
    {
        if (grid.empty()) return;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 2)
                    pos.push_back(make_pair(i, j));
            }
        }
    }

    bool find_fresh(vector<vector<int>> &gird)
    {
        if (gird.empty()) return false;
        bool b = false;
        int flag = 0;
        for (auto &i : gird)
        {
            for (auto &j : i)
            {
                if (j == 1)
                {
                    b = true;
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        return b;
    }
};


int main() {
    vector<vector<int>> a = {{2,1,1},{1,1,0},{0,1,1}};
    int c = Solution().orangesRotting(a);
    cout << c << endl;


    std::cout << std::endl;
    return 0;
}
