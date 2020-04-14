// 91. 解码方法

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int pre = 1, cur = 1;
        for (int i = 1; i < s.size(); i++) {
            int tmp = cur;
            if (s[i] == '0')
                if (s[i - 1] == '1' || s[i - 1] == '2') cur = pre;
                else return 0;
            else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
                cur = cur + pre;
            pre = tmp;
        }
        return cur;
    }
};


int main()
{

    return 0;
}
