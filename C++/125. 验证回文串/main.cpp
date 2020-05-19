// 125. 验证回文串

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isvaild(char c)
    {
        bool cond = (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
        if (!cond) return true;
        return false;
    }

    bool isPalindrome(string s) {
        if (s.empty()) return true;

        int begin = 0, end = s.size() - 1;
        while (begin < end)
        {
            while (begin < end && isvaild(s[begin])) ++begin;
            while (begin < end && isvaild(s[end])) --end;

            if (s[begin] >= 'A' && s[begin] <= 'Z') s[begin] += ('a' - 'A');
            if (s[end] >= 'A' && s[end] <= 'Z') s[end] += ('a' - 'A');

            if (s[begin] == s[end])
            {
                ++begin;
                --end;
            } else
                return false;
        }
        return true;
    }
};

int main()
{
    string s = "0P";
    cout << Solution().isPalindrome(s) << endl;
    return 0;
}