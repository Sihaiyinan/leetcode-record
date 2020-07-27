// 392. 判断子序列
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <cstring>
#include <set>


using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {

        int a = 0, b = 0;
        while (a < s.size() && b < t.size())
        {
            if (s[a] == t[b])
            {
                ++a;
            }
            ++b;
        }
        return a == s.size();
    }
};




int main()
{

    return 0;
}

