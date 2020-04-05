// 12. 整数转罗马数字

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int v[]={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string s[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        string res;
        for (int i = 0; i < 13; ++i)
        {
            while (num >= v[i])
            {
                num -= v[i];
                res += s[i];
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}
