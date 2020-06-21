// 93. 复原IP地址

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>


using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        if (s.empty()) return res;
        string str;
        huisu(s, 0, 0, str);
        return res;
    }

    int huisu(const string &s, int p, int n, string &str)
    {
        if (n == 4)
        {
            if (p == s.size())
                res.push_back(str);
            return 0;
        }

        // 没有剪枝
        for (int i = 1; i <= 3; ++i)
        {
            if (p + i > s.size()) continue;
            string sub = s.substr(p, i);
            if (isvalid(sub))
            {
                string t = str;
                if (n == 3)
                    str += sub;
                else
                    str += sub + ".";

                huisu(s, p + i, n + 1, str);
                str = t;
            }
        }
        return 0;
    }

    bool isvalid(const string & s)
    {
        if (s.empty() || s[0] == '0' && s.size() > 1) return false;
        int val = stoi(s);
        return val >= 0 && val <= 255;
    }
};



int main()
{
    string s = "010010";
    auto res = Solution().restoreIpAddresses(s);

    return 0;
}