// 45. 跳跃游戏 II

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int maxv = 0, end = 0, step = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (maxv >= i)
            {
                maxv = max(maxv, i + nums[i]);
                if (i == end)
                {
                    end = maxv;
                    ++step;
                }
            }
        }
        return step;
    }
};



int main()
{
    vector<int> a = {2,3,1,2,4,2,3};
    cout << Solution().jump(a) << endl;

    return 0;
}

