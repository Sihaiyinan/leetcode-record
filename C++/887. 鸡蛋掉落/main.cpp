#include<iostream>
#include<string>
#include <unordered_map>
#include <vector>


using namespace std;


/**
 * 鸡蛋掉落 动态规划
 * dp[k, n] 表示有 n 层 k 个鸡蛋时的最小测试次数
 * dp[k, n] = min(max(dp[k - 1, x - 1], dp[k, n - x])) + 1
 * dp[k - 1, x - 1] 表示当在 x 层鸡蛋碎了时，鸡蛋数 k - 1，然后从 x 层以下开始测试
 * dp[k, n - x] 表示当在 x 层鸡蛋没碎时，鸡蛋数不变， 然后从 x 层以上开始测试
 * 需要保证碎了和没碎两种情况的最大值最小
 */


class Solution1 {
    /**
     * 动态规划 + 二分查找
     */

    unordered_map<int, int> m;
    int dp(int k, int n)
    {
        // 100是鸡蛋的最大数量，1 * 100 + 1表示一层楼有一个鸡蛋时的次数 2030表示20层楼有30个鸡蛋时的次数
        if (m.find(n * 100 + k) == m.end())
        {
            int res = 0;
            if (n == 0) res = 0;
            else if (k == 1) res = n;
            else
            {
                int l = 1, h = n;
                while (l + 1 < h)
                {
                    int mid = l + (h - l) / 2;
                    int t1 = dp(k - 1, mid - 1);
                    int t2 = dp(k, n - mid);

                    if (t1 < t2) l = mid;
                    else if (t1 > t2) h = mid;
                    else l = h = mid;
                }

                res = min(max(dp(k - 1, l - 1), dp(k, n - l)), max(dp(k - 1, h - 1), dp(k, n - h))) + 1;

            }
            m[n * 100 + k] = res;
        }
        return m[n * 100 + k];
    }

public:
    int superEggDrop(int K, int N) {
        if (N == 0) return 1;
        return dp(K, N);
    }
};

class Solution {
    /**
     * 动态规划
     */

public:
    unordered_map<int, int> m;

    int dp(int k, int n)
    {
        if (m.find(n * 100 + k) == m.end())
        {
            int res = 0;
            if (n == 0) res = 0;
            else if (k == 1) res = n;
            else
            {
                int min_val = INT_MAX;
                for (int i = 1; i <= n; ++i)
                {
                    int t1 = dp(k - 1, i - 1);
                    int t2 = dp(k, n - i);
                    min_val = min(min_val, max(t1, t2));
                }
                res = min_val + 1;
            }
            m[n * 100 + k] = res;
        }
        return m[n * 100 + k];
    }

    int superEggDrop(int K, int N) {
        if (N == 0) return 1;
        return dp(K, N);
    }
};

class Solution2 {
    /**
     * 数学法
     */
public:
    int superEggDrop(int K, int N) {
        if (N == 1) {
            return 1;
        }
        vector<vector<int>> f(N + 1, vector<int>(K + 1));
        for (int i = 1; i <= K; ++i) {
            f[1][i] = 1;
        }
        int ans = -1;
        for (int i = 2; i <= N; ++i) {
            for (int j = 1; j <= K; ++j) {
                f[i][j] = 1 + f[i - 1][j - 1] + f[i - 1][j];
            }
            if (f[i][K] >= N) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};


int main()
{
    vector<int> N = {1,51,3,64,88,12,25,36,94,150,600,30,77,96,100};
    vector<int> K = {0,6,12,10,3,1,54,22,5,6,7,8,3, 50, 25};

    for (int i = 0; i < N.size(); ++i)
    {
        cout << Solution().superEggDrop(K[i], N[i]) << ' ';
    }
    cout << endl;
    for (int i = 0; i < N.size(); ++i)
    {
        cout << Solution1().superEggDrop(K[i], N[i]) << ' ';
    }
    return 0;
}