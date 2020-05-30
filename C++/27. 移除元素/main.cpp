// 27. 移除元素

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;

        int res = nums.size();
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == val)
            {
                nums.erase(nums.begin() + i);
                --i;
                --res;
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}