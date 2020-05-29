// 35. 搜索插入位置

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] >= target) return i;
        }
        return nums.size();
    }
};



int main()
{

    return 0;
}