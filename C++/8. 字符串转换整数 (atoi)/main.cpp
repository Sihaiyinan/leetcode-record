#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        // 数字的格式可以用 A[.[B]][e|EC]表示
        // 其中A和C都是整数（可以有符号）， B是一个无符号整数

        if (str.empty()) return 0;
        int pos = 0;
        while (pos < str.size() && str[pos] == ' ') ++pos; // 去除前段空格



    }

    int get_integer(const string &str, int &p)
    {
        if (str[p] == '+' || str[p] == '-')
            ++p;
        return get_unsigned_integer(str, p);
    }
    int get_unsigned_integer(const string &str, int &p)
    {
        int before = p;

    }
};

int main()
{
    return 0;
}
