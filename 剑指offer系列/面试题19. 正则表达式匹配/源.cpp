// 面试题19. 正则表达式匹配

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isMatch1(string s, string p) {
        return matchCore(s, 0, p, 0);
    }

    bool matchCore(const string &s, int sp, const string &p, int pp)
    {
        if ((sp == s.size()) && (pp == p.size()))    // 当字符串匹配完且模式匹配完时，返回真
            return true;
        if ((sp != s.size()) && (pp == p.size()))    // 当字符串没匹配完但是模式匹配完时，返回假；
            return false;

        if (p[pp + 1] == '*')     // 当模式的下一个字符为*时分为三种情况，*前的字符不匹配，匹配1次和匹配多次
        {
            if (p[pp] == s[sp] || (p[pp] == '.' && (sp != s.size())))      // 如果当前字符串中的字符和模式中的字符匹配
                return matchCore(s, sp + 1, p, pp + 2)  // 等于*号前边的字符只匹配一次
                       || matchCore(s, sp + 1, p, pp)    // *前边的字符需要匹配多次
                       || matchCore(s, sp, p, pp + 2);   // *前的字符匹配0次
            else
                return matchCore(s, sp, p, pp + 2);
        }
        if (s[sp] == p[pp] || (p[pp] == '.' && (sp != s.size())))
            return matchCore(s, sp + 1, p, pp + 1);

        return false;
    }


    /*
     * 动态规划
     * dp[i, j] 表示 s[0:i]与p[0:j]是否匹配
     */

    bool isMatch(string s, string p) {
        map<pair<int, int>, bool> m;
        return dp(0, 0, s, p, m);
    }

    bool dp(int i, int j, string &s, string &p, map<pair<int, int>, bool> &m)
    {
        if (m.find(make_pair(i, j)) == m.end())    // 如果哈希表里没有找到（i，j）的话需要进行判断，找到的话直接返回结果
        {
            bool ans;
            if (j == p.size())
                ans = (i == s.size());
            else
            {
                bool cur_match = (i < s.size()) && ((s[i] == p[j]) || (p[j] == '.'));    // 判断当前当前子是否匹配
                if (j + 1 < p.size() && p[j + 1] == '*')    // 如果p的下一个字符是*， 有两种情况，一种是匹配0次， 一种是匹配无数次
                    ans = dp(i, j + 2, s, p, m) || (cur_match && dp(i + 1, j, s, p, m));
                else
                    ans = cur_match && dp(i + 1, j + 1, s, p, m);    // 如果p的下一个字符不是*，则比较两个字符串的下一个
            }
            m[make_pair(i, j)] = ans;
        }
        return m[make_pair(i, j)];
    }
};

int main()
{
    string a = "aa", b = ".*";
    cout << Solution().isMatch(a, b) << endl;

    return 0;
}