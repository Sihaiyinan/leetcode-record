// 56. 合并区间

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty()) return res;
        sort(intervals.begin(), intervals.end());

        auto a = intervals[0];
        for (int i = 1; i < intervals.size(); ++i)
        {
            auto b = intervals[i];
            int left = max(a[0], b[0]);
            int right = min(a[1], b[1]);
            if (right >= left)
            {
                a[0] = min(a[0], b[0]);
                a[1] = max(a[1], b[1]);
            } else
            {
                res.push_back(a);
                a = b;
            }
        }
        res.push_back(a);
        return res;
    }
};


int main()
{

    return 0;
}
