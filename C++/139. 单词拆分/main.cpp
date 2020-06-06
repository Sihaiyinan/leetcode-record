// 139. 单词拆分

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <unordered_map>


using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.empty() || wordDict.empty()) return false;

        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;

        unordered_map<string, int> m;
        for (auto &i : wordDict) m[i] = 1;

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                string sub = s.substr(i, j - i);
                if (dp[i] && m.count(sub) != 0)
                    dp[j] = true;
            }
        }
        return dp.back();
    }
};



int main()
{
    string s = "leetcode";
    vector<string> word = {"leet", "code"};
    cout << Solution().wordBreak(s, word) << endl;

    return 0;
}