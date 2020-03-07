// 面试题43. 1～n整数中1出现的次数

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // 方法1
    int countDigitOne1(int n) {

        int count = 0;
        for (int i = 0; i <= n; ++i)
        {
            string s = to_string(i);
            count += count_one(s);
        }
        return count;
    }

    int count_one(const string &s)
    {
        int num = 0;
        for (auto &c : s)
        {
            if (c == '1')
                ++num;
        }
        return num;
    }

    // 方法2，数学
    int countDigitOne(int n)
    {
        int countr = 0;
        for (long long i = 1; i <= n; i *= 10) {
            long long divider = i * 10;
            countr += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
        }
        return countr;
    }

};

int main() {
    int n = 12;
    cout << Solution().countDigitOne(n) << endl;

    std::cout << std::endl;
    return 0;
}
