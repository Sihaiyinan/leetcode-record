// 680. 验证回文字符串 Ⅱ

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        if (s.empty()) return false;
        int begin = 0, end = s.size() - 1;

        int flag = 0;
        while (begin < end)
        {
            if (s[begin] == s[end])
            {
                begin++;
                end--;
            } else
            {
                return ishuiwen(s, begin + 1, end) || ishuiwen(s, begin, end - 1);
            }
        }
        return true;
    }

    bool ishuiwen(string &s, int left, int right)
    {
        while (left < right)
        {
            if (s[left] != s[right])
                return false;
            ++left;
            --right;
        }
        return true;
    }
};

int main()
{

    return 0;
}