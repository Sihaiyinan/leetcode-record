// 1014. 最佳观光组合

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>


using namespace std;


class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        if (A.empty()) return 0;

        int res = INT_MIN, mx = A[0] + 0;
        for (int j = 1; j < A.size(); ++j)
        {
            res = max(res, mx + A[j] - j);
            mx = max(mx, A[j] + j);
        }
        return res;
    }
};


int main()
{
    return 0;
}