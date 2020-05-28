// 394. 字符串解码

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string res;
        int num = 0;
        vector<pair<int, string>> v;

        for (auto c : s)
        {
            // 当遇到 '[' 时，将 '[' 前的数字和字符串压入栈中
            if (c == '[')
            {
                v.emplace_back(num, res);
                num = 0;
                res = "";
            }
            // 当遇到 ']' 时， 将栈顶弹出，此时数字即为当前res需要重复的次数
            else if(c == ']')
            {
                auto tmp = v.back();
                v.pop_back();
                string t = res;
                for (int i = 0; i < tmp.first - 1; ++i)
                    res += t;
                res = tmp.second + res;
            }
            else if(c >= '0' && c <= '9')
                num = num * 10 + c - '0';
            else
                res += c;
        }
        return res;
    }
};



int main() {


    return 0;
}
