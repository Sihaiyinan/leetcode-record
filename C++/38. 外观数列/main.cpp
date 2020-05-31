// 38. 外观数列

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string base = "1";

        while (n > 1)
        {
            int t = 0;
            string s;
            char c = base[0];
            for (char i : base)
            {
                if (i == c)
                {
                    t += 1;
                }
                else
                {
                    s += to_string(t) + c;
                    c = i;
                    t = 1;
                }
            }
            s += to_string(t) + c;
            base = s;
            --n;
        }

        return base;
    }
};

int main()
{
    cout << Solution().countAndSay(5) << endl;
    return 0;
}