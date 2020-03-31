#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long res = 0, xx = x;
        while (x)
        {
            res = res * 10 + x % 10;
            if (res > 0x7FFFFFFF || res < (int)0x80000000) return false;
            x /= 10;
        }
        if (res == xx) return true;
        return false;
    }
};

int main()
{
    return 0;
}
