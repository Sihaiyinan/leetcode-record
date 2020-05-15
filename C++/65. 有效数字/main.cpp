// 65. 有效数字

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        if (s.empty()) return false;

        int pos = 0;
        while (pos < s.size() && s[pos] == ' ') ++pos;  //去除前段空格
        bool numeric = scanInteger(s, pos);      // 判断字符串开头是否存在整数

        // 如果出现 '.'接下来是小数部分
        if (s[pos] == '.')
        {
            ++pos;

            // 1. 小数可以没有整数部分， .123 == 0.123
            // 2. 小数点后面可以没有数字， 123. == 123.0
            numeric = scanUnsignedInteger(s, pos) || numeric;
        }

        // 如果出现e，接下来是指数部分
        if (s[pos] == 'e' || s[pos] == 'E')
        {
            ++pos;

            // 1. 当e前面没有数字时字符串不能表示成数字
            // 2. 当e后面没有整数时不能表示成数字
            numeric = scanInteger(s, pos) && numeric;
        }
        while (pos < s.size() && s[pos] == ' ') ++pos;    // 去除后面的空格

        return numeric && pos == s.size();
    }

    // 判断是否存在无符号整数
    bool scanUnsignedInteger(const string &str, int &p)
    {
        int before = p;  // 记录p之前的位置
        while (p != str.size() && str[p] >= '0' && str[p] <= '9')
            ++p;

        return p > before;  // 如果p == before 说明不存在无符号整数
    }

    // 判断是否存在整数
    bool scanInteger(const string &str, int &p)
    {
        if (str[p] == '+' || str[p] == '-')
            ++p;
        return scanUnsignedInteger(str, p);
    }
};

int main()
{
    string a = "aa", b = ".*";
    cout << Solution().isMatch(a, b) << endl;

    return 0;
}