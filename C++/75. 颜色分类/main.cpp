// 75. 颜色分类

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    void sortColors(vector<int>& nums) {
        int begin = 0, end = nums.size() - 1, cur = 0;
        while (cur < end)
        {
            // 如果当前的数字是0，移动到前边
            if (nums[cur] == 0)
            {
                swap(nums[cur], nums[begin]);
                ++cur;
                ++begin;
            }
            // 如果当前的数字是2，移动到后面
            else if (nums[cur] == 2)
            {
                swap(nums[cur], nums[end]);
                --end;
            }
            else
            {
                ++cur;
            }
        }
    }
};


int main()
{

    return 0;
}