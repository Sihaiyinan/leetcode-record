#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string re = strs[0];
        for (int i = 1; i < strs.size(); ++i)
        {
            int min_len = min(re.size(), strs[i].size());
            for (int j = 0; j < min_len; ++j)
            {
                if (re[j] != strs[i][j])
                {
                    re = re.substr(0, j);
                    break;
                }
            }
            re.size() < strs[i].size() ? re = re : re = strs[i];
            if (re.empty()) break;
        }
        return re;
    }

    string longestCommonPrefix2(vector<string>& strs) {
        string re;
        int len = strs.size();
        if (len == 0) return re;

        int min_len = 0x7FFFFFFF;
        for (auto &s : strs)
            if (s.size() < min_len) min_len = s.size();

        int flag = 0;
        for (int i = 0; i < min_len; ++i)
        {
            for (int j = 1; j < len; ++j)
            {
                if (strs[j - 1][i] != strs[j][i])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                re += strs[0][i];
                flag = 0;
            }
        }
        return re;
    }
};

int main()
{
    vector<string> a = {"flower","flow","flight"};
    string re = Solution().longestCommonPrefix(a);
    for (auto s : re) cout << s;
    cout << endl;
    return 0;
}