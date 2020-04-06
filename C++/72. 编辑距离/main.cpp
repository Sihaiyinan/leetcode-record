// 72. 编辑距离

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

class Solution {
public:
    // 动态规划
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        if (n * m == 0) return m + n;
        int dp[n + 1][m + 1];
        for (int i = 0; i <n + 1; ++i)
            dp[i][0] = i;
        for (int i = 0; i < m + 1; ++i)
            dp[0][i] = i;

        for (int i = 1; i < n + 1; ++i)
        {
            for (int j = 1; j < m + 1; ++j)
            {
                int a = dp[i - 1][j] + 1;
                int b = dp[i][j - 1] + 1;
                int c = dp[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1]) c += 1;
                dp[i][j] = min(a, min(b, c));
            }
        }
        return dp[n][m];
    }
};

int main()
{

    return 0;
}
