// 41. 缺失的第一个正数

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>


using namespace std;


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int, int> m;
        for (auto i : nums) m[i]++;

        if (m.empty()) return 1;
        if (m.begin()->first > 1 || m.end()->first < 1) return 1;

        auto it = m.begin();
        while (it->first < 1) ++it;

        int t = 1;
        for (auto j = it; j != m.end(); ++j)
        {
            if (j->first != t) return t;
            ++t;
        }
        if (t == (--m.end())->first + 1) return t;
        return 1;
    }
};


int main()
{
    vector<int> a = {0,1,1,2,2};
    cout << Solution().firstMissingPositive(a) << endl;

    return 0;
}