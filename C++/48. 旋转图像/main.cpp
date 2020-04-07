// 72. 编辑距离

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        int len = matrix[0].size();
        rotateCore(matrix, 0);
    }

    void rotateCore(vector<vector<int>>& matrix, int a)
    {
        int len = matrix[0].size() - 1;
        if (a > len / 2) return;
        for (int i = a; i < len - a; ++i)
        {
            int t = matrix[a][i];
            matrix[a][i] = matrix[len - i][a];
            matrix[len - i][a] = matrix[len - a][len - i];
            matrix[len - a][len - i] = matrix[i][len - a];
            matrix[i][len - a] = t;
        }
        rotateCore(matrix, a + 1);
    }
};

int main()
{
    vector<vector<int>> a = {{2,29,20,26,16,28},{12,27,9,25,13,21},{32,33,32,2,28,14},{13,14,32,27,22,26},{33,1,20,7,21,7},{4,24,1,6,32,34}};

    Solution().rotate(a);
    return 0;
}
