// 13. 罗马数字转整数

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<string, int> m;
        m["M"] = 1000; m["CM"] = 900; m["D"] = 500; m["CD"] = 400; m["C"] = 100; m["XC"] = 90;
        m["L"] = 50; m["XL"] = 40; m["X"] = 10; m["IX"] = 9; m["V"] = 5; m["IV"] = 4; m["I"] = 1;

        int res = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (i + 1 < s.size() && m[s.substr(i,1)] < m[s.substr(i + 1, 1)])
            {
                res = res + m[s.substr(i, 2)];
                ++i;
            } else
            {
                res = res + m[s.substr(i, 1)];
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}
