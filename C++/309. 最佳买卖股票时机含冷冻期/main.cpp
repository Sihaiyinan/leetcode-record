// 309. 最佳买卖股票时机含冷冻期

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
    // 方法一
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int dp0 = 0, dp1 = INT_MIN, pre = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            int t = dp0;
            dp0 = max(dp0, dp1 + prices[i]);
            dp1 = max(dp1, pre - prices[i]);  // 存在冻结的话从后天减去
            pre = t;
        }
        return dp0;
    }

    // 方法二
    int maxProfit1(vector<int>& prices) {
        if (prices.empty()) return 0;

        int dp0 = 0;        // 手上没有股票，且不在冷冻期
        int dp1 = 0;        // 手上没有股票，且在冷冻期
        int dp2 = INT_MIN;  // 手上有股票
        for (int i = 0; i < prices.size(); ++i)
        {
            dp2 = max(dp2, dp0 - prices[i]);    // 今天手上有股票，
            // 可能是我昨天手上就有股票，今天不想卖
            // 或者我昨天手上没有股票，今天不是冷冻期所以我买了

            dp0 = max(dp0, dp1);                // 今天不是冷冻期为啥手上没有股票呢
            // 可能是我手里本来就没股票，可能是我不是冷冻期的时候卖掉了

            dp1 = dp2 + prices[i];              // 今天是冷冻期，说明我昨天已经卖过股票了
            // 那我手里的价值就是昨天卖股票赚到的钱
        }
        return max(dp0, dp1);
    }
};

int main()
{

    return 0;
}