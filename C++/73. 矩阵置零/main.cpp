// 73. 矩阵置零
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <cstring>
#include <set>


using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        map<int, int> mr, mc;

        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    mr[i]++;
                    mc[j]++;
                }
            }
        }
        for (auto &i : mr)
        {
            for (int j = 0; j < col; ++j)
            {
                matrix[i.first][j] = 0;
            }
        }

        for (auto &i : mc)
        {
            for (int j = 0; j < row; ++j)
            {
                matrix[j][i.first] = 0;
            }
        }
    }
};


int main()
{

    return 0;
}

