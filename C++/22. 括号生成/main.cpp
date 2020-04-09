// 22. 括号生成

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n == 0)
        {
            res.push_back("");
            return res;
        }

        string s = "(";
        huisu(res, s, n,  1, 0);

        return res;
    }

    void huisu(vector<string> &res, string &cur, int n, int a, int b) {
        if (cur.size() == 2*n)
        {
            res.push_back(cur);
            return;
        }

        if (a < n)
        {
            cur += "(";
            huisu(res, cur, n, a + 1, b);
            cur.pop_back();
        }
        if (b < a)
        {
            cur += ")";
            huisu(res, cur, n, a, b + 1);
            cur.pop_back();
        }
    }
};

int main()
{
    int n = 3;
    vector<string> res = Solution().generateParenthesis(n);
    for (auto i : res)
        cout << i << endl;

    return 0;
}
