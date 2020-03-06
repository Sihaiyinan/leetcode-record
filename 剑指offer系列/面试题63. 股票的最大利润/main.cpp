// 面试题63. 股票的最大利润

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // 方法1
    int maxProfit1(vector<int>& prices) {
        if (prices.empty()) return 0;
        int maxc = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            int t = prices[i];
            for (int j = i + 1; j < prices.size(); ++j)
            {
                if (prices[j] - t > maxc)
                    maxc = prices[j] - t;
            }
        }
        return maxc;
    }

    // 方法2
    int maxProfit2(vector<int>& prices) {
        if (prices.empty()) return 0;

        int minc = 0x7FFFFFFF;  // 最小值
        int maxc = 0;           // 最大利润

        for (auto &i : prices)
        {
            if (i < minc)
                minc = i;
            else if (i - minc > maxc)
                maxc = i - minc;
        }
        return maxc;
    }

    // 方法3， 动态规划
    int maxProfit(vector<int>& prices) {
        int sell = 0, buy = 0x80000000;

        for (int i = 0; i < prices.size(); ++i)
        {
            sell = max(sell, buy + prices[i]);
            buy = max(buy, -prices[i]);
        }
        return sell;
    }

};


int main() {
    vector<int> a = {7,1,5,3,6,4};
    cout << Solution().maxProfit(a) << endl;

    std::cout << std::endl;
    return 0;
}
