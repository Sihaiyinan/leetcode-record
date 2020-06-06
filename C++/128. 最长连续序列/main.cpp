// 128. 最长连续序列

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <unordered_map>


using namespace std;


class Solution {
public:
    // 方法一
    int longestConsecutive1(vector<int>& nums) {
        if (nums.empty()) return 0;
        map<int, int> m;
        for (int & num : nums)  m[num]++;

        int max_val = 0, cur = 1;
        auto it1 = m.begin(), it2 = ++m.begin();
        for ( ; it2 != m.end(); ++it2)
        {
            if (it2->first - it1->first == 1)
            {
                ++cur;
            } else
            {
                max_val = max(max_val, cur);
                cur = 1;
            }
            ++it1;
        }
        max_val = max(max_val, cur);
        return max_val;
    }

    // 方法二
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> num_set;
        for (auto &i : nums) num_set.insert(i);

        int max_val = 0;

        for (auto &i : nums)
        {
            if (!num_set.count(i - 1))
            {
                int cur_num = i;
                int cur_len = 1;

                while (num_set.count(cur_num + 1))
                {
                    cur_num += 1;
                    cur_len += 1;
                }

                max_val = max(max_val, cur_len);
            }
        }
        return max_val;
    }

    // 方法三， 并查集
    unordered_map<int, int> a;
    int find(int x)
    {
        return a.count(x) ? a[x] = find(a[x]) : x;
    }

    int longestConsecutive2(vector<int>& nums) {
        for (auto i : nums) a[i] = i + 1;
        int res = 0;
        for (auto i : nums)
        {
            int y = find(i + 1);
            res = max(res, y - i);
        }
        return res;
    }

};

int main()
{
    vector<int> nums = {1,2,2,3,4,5,6};
    cout << Solution().longestConsecutive(nums) << endl;

    return 0;
}