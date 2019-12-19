#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0, l = 0, r = 0;
        string sub;
        while (s.begin() + r != s.end())
        {
            int pos = sub.find(s[r]);
            if (pos != string::npos) l += pos + 1;
            r++;
            sub = s.substr(l, r - l);
            if (sub.length() > max_len) max_len = sub.length();
        }
        return max_len;
    }
};

int main()
{
    string s = "abcaabcbb";
    cout << Solution().lengthOfLongestSubstring(s) << endl;
    return 0;
}