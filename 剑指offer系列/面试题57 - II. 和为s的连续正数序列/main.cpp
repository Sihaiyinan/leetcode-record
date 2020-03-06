// 面试题57 - II. 和为s的连续正数序列

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // 滑窗法
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> re;
        if (target < 3)
            return re;
        int begin = 1;
        int end = 2;
        int sum = 3;
        int mid = target / 2 + 2;

        vector<int> tmp;
        while (end < mid)
        {
            if (sum == target)
            {
                for (int i = begin; i <= end; ++i)
                    tmp.push_back(i);
                re.push_back(tmp);
                tmp.clear();
            }

            while (sum > target && begin < mid)
            {
                sum -= begin;
                ++begin;
                if (sum == target)
                {
                    for (int i = begin; i <= end; ++i)
                        tmp.push_back(i);
                    re.push_back(tmp);
                    tmp.clear();
                }
            }
            ++end;
            sum += end;
        }
        return re;
    }
};

int main() {
    int n = 3;
    vector<vector<int>> re = Solution().findContinuousSequence(n);


    std::cout << std::endl;
    return 0;
}
