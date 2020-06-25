// 204. 计数质数
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 方法一
    int countPrimes1(int n) {
        int count = 0;
        for (int i = 2; i < n; ++i)
        {
            int f = 0;
            for (int j = 2; j * j <= i; ++j)
            {
                if (i % j == 0)
                {
                    f = 1;
                    break;
                }
            }
            if (f == 0) ++count;
        }
        return count;
    }

    // 方法二 筛选法
    int countPrimes(int n) {
        vector<int> isPrim(n, 1);

        for (int i = 2; i * i < n; ++i)
        {
            if (isPrim[i])
            {
                for (int j = i * i; j < n; j += i)
                    isPrim[j] = 0;
            }
        }

        int c = 0;
        for (int i = 2; i < n; ++i)
        {
            if (isPrim[i]) ++c;
        }
        return c;
    }
};

int main()
{


    return 0;
}