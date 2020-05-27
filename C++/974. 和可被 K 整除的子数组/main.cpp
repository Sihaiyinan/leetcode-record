// 974. 和可被 K 整除的子数组

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int res = 0, sum = 0;
        unordered_map<int, int> m;
        m[0] = 1;   // 当整个数组可以被K整除时

        for (auto i : A)
        {
            sum += i;
            int mod = (sum % K + K) % K;   // C++ 复数取余还是复数，需要进行处理
            if (m.find(mod) != m.end())
                res += m[mod];
            m[mod]++;
        }
        return res;
    }
};



int main() {
    vector<int> nums = {4,5,0,-2,-3,1};
    int k = 5;
    cout << Solution().subarraysDivByK(nums, k) << endl;


    return 0;
}
