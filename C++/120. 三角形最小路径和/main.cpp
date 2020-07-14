// 120. 三角形最小路径和

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <cstring>


using namespace std;


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int s = triangle.size();

        int min_len = INT_MAX;
        vector<int> dp(s * s);
        dp[0] = triangle[0][0];

        for (int i = 1; i < s; ++i)
        {
            for (int j = 0; j < s; ++j)
            {
                if (j >= triangle[i].size()) break;

                if (j - 1 >= 0 && j < triangle[i - 1].size())
                    dp[i * s + j] = min(dp[(i - 1) * s + j - 1], dp[(i - 1) *s + j]) + triangle[i][j];
                else if (j - 1 < 0)
                    dp[i * s + j] = dp[(i - 1) *s + j] + triangle[i][j];
                else if (j >= triangle[i - 1].size())
                    dp[i * s + j] = dp[(i - 1) * s + j - 1] + triangle[i][j];
            }
        }
        return *min_element(dp.begin() + (s - 1) * s, dp.end());
    }
};


int main()
{
    vector<vector<int>> t = {{1},{-5,-2},{3,6,1},{-1,2,4,-3}};
    cout << Solution().minimumTotal(t) << endl;

    return 0;
}

