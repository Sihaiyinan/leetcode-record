// 647. 回文子串

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>


using namespace std;


class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            ++res;
            int l = i, r = i;
            while (r + 1 < s.size())
            {
                if (l == i && s[l] == s[r + 1])
                {
                    ++res;
                    ++r;
                }
                else if (l - 1 >= 0 && s[l - 1] == s[r + 1])
                {
                    --l;
                    ++r;
                    ++res;
                }
                else
                    break;
            }
        }
        return res;
    }
};


int main()
{
    string str = "abc";
    cout << Solution().countSubstrings(str) << endl;

    return 0;
}

