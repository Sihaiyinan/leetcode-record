// 334. 递增的三元子序列
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <cstring>
#include <set>


using namespace std;


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        int a = INT_MAX;
        int b = INT_MAX;

        for (auto n : nums)
        {
            if (n <= a)
                a = n;
            else if (n <= b)
                b = n;
            else
                return true;
        }
        return false;
    }
};


int main()
{

    return 0;
}

