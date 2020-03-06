// 面试题53 - II. 0～n-1中缺失的数字

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // 方法1
    int missingNumber1(vector<int>& nums) {
        if (nums.empty()) return 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i != nums[i])
                return i;
        }
        return nums.size();
    }


    // 方法2，二分法
    int missingNumber(vector<int>& nums) {
        if (nums.empty()) return 0;
        int begin = 0, end = nums.size() - 1;

        int re = 0;
        while (begin <= end)
        {
            int mid = (begin + end) >> 1;
            if (nums[mid] != mid)
            {
                if (mid == 0 || mid - 1 == nums[mid - 1])
                    return mid;
                end = mid - 1;
            } else
            {
                begin = mid + 1;
            }
        }
        if (begin == nums.size())
            re = begin;
        return re;
    }

};


int main() {
    vector<int> a = {0,1,2,3,4,5,6,7,9};
    cout << Solution().missingNumber(a) << endl;

    std::cout << std::endl;
    return 0;
}
