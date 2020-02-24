#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 深度优先遍历
    vector<string> letterCombinations(string digits) {
        vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> re;
        int len = digits.size();
        if (len == 0) return re;

        string cur_string;
        find_string(digits, map, cur_string, re);
        return re;
    }

    static int find_string(string sub_digits, vector<string>& map, const string& cur_string, vector<string>& res)
    {
        if (sub_digits.empty())
        {
            res.push_back(cur_string);
            return 0;
        }
        for (auto i : map[sub_digits[0] - '0'])
        {
            string sub = sub_digits;
            find_string(sub.erase(0, 1), map, cur_string + i, res);
        }
        return 0;
    }

    // 广度优先遍历
    vector<string> letterCombinations2(string digits) {
        vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> re;
        int len = digits.size();
        if (len == 0) return re;

        re.emplace_back("");
        for (auto &num : digits)
        {
            vector<string> cur;
            for (auto &old_string : re)
            {
                for (auto &cur_str : map[num - '0'])
                {
                    cur.emplace_back(old_string + cur_str);
                }
            }
            re = cur;
        }
        return re;
    }
};

int main()
{
    string a = "27";
    vector<string> re = Solution().letterCombinations(a);
    for (const auto& i : re) cout << i <<' ';
    cout << endl;
    return 0;
}