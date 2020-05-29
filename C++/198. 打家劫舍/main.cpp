// 198. 打家劫舍

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;

        int a = 0, b = 0, res = 0;
        for (int num : nums)
        {
            res = max(b, a + num);
            a = b;
            b = res;
        }
        return res;
    }
};


int main()
{

    return 0;
}