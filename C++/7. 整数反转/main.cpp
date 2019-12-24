#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long num = 0;
        for (; x; num = num * 10 + x % 10, x = x / 10);
        return num < 0x7FFFFFFF && num > int(0x80000000) ? num : 0;
    }
};

int main()
{
    int a = -124;
    int re = Solution().reverse(a);
    cout << re << endl;
    return 0;
}