// 01背包问题

/*
 * 有 N 件物品和一个容量是 V 的背包。 每个物品只能用一次。
 * 第 i 件物品的体积是 vi， 价值是 wi。
 * 求解将哪些物品放入背包，可使得这些物品的总体积不超过背包的容量，且价值最大。
 *
 * 动态规划
 *
 * f[i][j] 表示 i 件物品，体积为 j 时的最大价值。
 * 物品可选可不选，因此
 *
 * 1、f[i][j] = f[i - 1][j]
 * 2、f[i][j] = f[i - 1][j - v[i]] + w[i]
 * f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i])
 *
 *
 * */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, v;
    cin >> n >> v;
    vector<int> cost(n + 1), value(n + 1);

    int i = 1;
    while (i <= n)
    {
        cin >> cost[i] >> value[i];
        ++i;
    }

    int dp[n + 1][v + 1];
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= v; ++j)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= v; ++j)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= cost[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + value[i]);
        }
    }
    cout << dp[n][v] << endl;


    return 0;
}