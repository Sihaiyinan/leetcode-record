#include <iostream>
#include <vector>

using namespace std;

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        qsort(nums.data(), len, sizeof(int), compare);

        int closest = 0x7FFFFFFF;
        int re = target;
        for (int i = 0; i < len; ++i)
        {
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            int left = i + 1;
            int right = len - 1;
            while (left < right)
            {
                int tmp = nums[i] + nums[left] + nums[right];
                int cha = tmp - target;
                if (0 == cha)
                    return target;
                if (abs(cha) < closest)
                {
                    closest = abs(cha);
                    re = tmp;
                }
                if (cha < 0)
                {
                    left++;
                    while (left < right && nums[left - 1] == nums[left]) left++;
                }
                if (cha > 0)
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
    vector<int> a = {-1, 2, 1, -4};
    int b = 1;
    cout << Solution().threeSumClosest(a, b) << endl;
    return 0;
}