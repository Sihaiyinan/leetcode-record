#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
        {
            m[nums[i]] = i;
        }

        vector<int> re;
        for (int i = 0; i < nums.size(); ++i)
        {
            int t = target - nums[i];
            auto it = m.find(t);
            if (it != m.end() && it->second != i)
            {
                re.push_back(i);
                re.push_back(m[t]);
                break;
            }
        }
        return re;
    }
};


int main()
{
    Solution S;
    vector<int> re, nums = {3,2,4};
    int target = 6;
    re = S.twoSum(nums, target);
    for (auto i : re) cout << i << endl;
    return 0;
}