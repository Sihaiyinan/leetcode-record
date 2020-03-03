// 面试题38. 字符串的排列

#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> re;
        if (s.empty()) return re;
        set<string> res;

        string cur = "";
        dfs(s,0, cur, res);
        for (auto it = res.begin(); it != res.end(); ++it)
        {
            re.push_back(*it);
        }

        return re;
    }

    void dfs(string &str, int begin, string &cur_str, set<string> &re)
    {
        if (begin >= str.size())
        {
            re.insert(cur_str);
            return;
        }
        for (int i = begin; i < str.size(); ++i)
        {
            cur_str.push_back(str[i]);
            swap(str[i], str[begin]);
            dfs(str, begin + 1, cur_str, re);
            swap(str[i], str[begin]);
            cur_str.pop_back();
        }
    }
};


int main() {
    string s = "abc";
    vector<string> re = Solution().permutation(s);


    std::cout << std::endl;
    return 0;
}
