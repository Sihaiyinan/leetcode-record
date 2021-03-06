// 32. 最长有效括号

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) return 0;

        int res = 0;
        vector<int> dp(s.size());
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == ')') {
                if (s[i - 1] == '(')
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                else if (i - dp[i - 1] > 0 && s[i - 1 - dp[i - 1]] == '(')
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
            }
            res = res > dp[i] ? res : dp[i];
        }
        return res;
    }
};

int main()
{
    string s = "(()";
    cout << Solution().longestValidParentheses(s) << endl;
    return 0;
}
