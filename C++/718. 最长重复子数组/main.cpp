// 718. 最长重复子数组

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
    int findLength(vector<int>& A, vector<int>& B) {
        if (A.empty() || B.empty()) return 0;

        int dp[1000][1000];
        memset(dp, 0, sizeof(dp));

        int max_val = 0;
        for (int i = 0; i < A.size(); ++i)
        {
            for (int j = 0; j < B.size(); ++j)
            {
                if (A[i] == B[j])
                {
                    if (i == 0 || j == 0) dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    max_val = max(max_val, dp[i][j]);
                }

            }
        }
        return max_val;
    }
};


int main()
{

    return 0;
}