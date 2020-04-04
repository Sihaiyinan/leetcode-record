// 42. 接雨水

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int trap1(vector<int>& height) {
        if (height.empty()) return 0;
        int res = 0;
        int len = height.size();
        vector<int> lmax(len), rmax(len);
        lmax[0] = height[0];
        for (int i = 1; i < len; ++i)
        {
            lmax[i] = max(height[i], lmax[i-1]);
        }
        rmax[len - 1] = height[len - 1];
        for (int i = len - 2; i >= 0; --i)
        {
            rmax[i] = max(height[i], rmax[i+1]);
        }
        for (int i = 0; i < len; ++i)
        {
            res += min(lmax[i], rmax[i]) - height[i];
        }
        return res;
    }

    int trap(vector<int> & height)
    {
        int left = 0, right = height.size() - 1;
        int res = 0;
        int lmax = 0, rmax = 0;

        while (left < right)
        {
            if (height[left] < height[right])
            {
                height[left] >= lmax ? (lmax = height[left]) : res += (lmax - height[left]);
                ++left;
            } else
            {
                height[right] >= rmax ? (rmax = height[right]) : res += (rmax - height[right]);
                --right;
            }
        }
        return res;
    }

};

int main()
{
    vector<int> a = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << Solution().trap(a) << endl;
    return 0;
}
