#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        int pos = 0;
        while (pos < str.size() && str[pos] == ' ') ++pos; // 去除前段空格

        return get_integer(str, pos);
    }

    long long get_unsigned_integer(const string &str, int &p, int flag)
    {
        long long res = 0;
        int overflow = 0;
        while (p < str.size() && str[p] >= '0' && str[p] <= '9')
        {
            res = res * 10 + (str[p] - '0');
            if (res > 0x7FFFFFFF || res < (int)0x80000000)
            {
                overflow = 1;
                break;
            }
            ++p;
        }
        if (overflow)
        {
            if (flag == 1) return 0x7FFFFFFF;
            else if (flag == -1) return (int)0x80000000;
        }
        return res * flag;
    }
    long long get_integer(const string &str, int &p)
    {
        int flag = 1;
        if (str[p] == '+')
            ++p;
        else if (str[p] == '-')
        {
            flag = -1;
            ++p;
        }
        return get_unsigned_integer(str, p, flag);
    }
};

int main()
{
    return 0;
}
