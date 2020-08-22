// 679. 24 点游戏

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>


using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        if (nums.empty()) return false;
        vector<double> l(nums.begin(), nums.end());
        return solve(l);
    }

    bool solve(vector<double> &l)
    {
        if (l.empty()) return false;
        if (l.size() == 1)
        {
            return fabs(l[0] - 24) < 1e-6;
        }

        int s = l.size();
        for (int i = 0; i < s; ++i)
        {
            for (int j = 0; j < s; ++j)
            {
                if (i == j) continue;
                vector<double> l2;
                for (int k = 0; k < s; ++k)
                {
                    if (i != k && j != k) l2.push_back(l[k]);
                }

                for (int k = 0; k < 4; ++k)
                {
                    if (k == 0) l2.push_back(l[i] + l[j]);
                    if (k == 1) l2.push_back(l[i] - l[j]);
                    if (k == 2) l2.push_back(l[i] * l[j]);
                    if (k == 3)
                    {
                        if (fabs(l[j]) < 1e-6) continue;
                        l2.push_back(l[i] / l[j]);
                    }
                    if (solve(l2)) return true;
                    l2.pop_back();
                }
            }
        }
        return false;
    }
};


int main()
{

    return 0;
}

