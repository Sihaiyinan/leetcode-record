#include <iostream>
#include <vector>

using namespace std;

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

class Solution {
public:

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> re;
        int len = nums.size();
        if (len < 3) return re;

        qsort(nums.data(), len, sizeof(int), compare);

        for (int i = 0; i < len - 2; ++i)
        {
            if (nums[i] > 0) return re;
            if (i > 0 && nums[i - 1] == nums[i]) continue;

            int left = i + 1;
            int right = len - 1;
            while (left < right)
            {
                int tmp = nums[i] + nums[left] + nums[right];
                if (tmp == 0)
                {
                    vector<int> t = {nums[i], nums[left], nums[right]};
                    re.push_back(t);
                    left++;
                    while (left < right && nums[left - 1] == nums[left]) left++;
                    right--;
                    while (left < right && nums[right + 1] == nums[right]) right--;
                }
                if (tmp < 0)
                {
                    left++;
                    while (left < right && nums[left - 1] == nums[left]) left++;
                }
                if (tmp > 0)
                {
                    right--;
                    while (left < right && nums[right + 1] == nums[right]) right--;
                }
            }
        }
        return re;
    }
};

int main()
{
    vector<int> a = {-1, 0, 1, 2, -1, -4};
    auto re = Solution().threeSum(a);
    for (const auto& i : re)
    {
        for (auto ii : i)
        {
            cout << ii << ' ';
        }
        cout << endl;
    }

    return 0;
}