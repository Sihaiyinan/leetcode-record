// 739. 每日温度

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_set>
#include <unordered_map>


using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if (T.empty()) return T;

        vector<int> res(T.size());
        vector<int> s;
        for (int i = T.size() - 1; i >= 0; --i)
        {
            while (!s.empty() && T[i] >= T[s.back()])
                s.pop_back();
            if (!s.empty()) res[i] = s.back() - i;
            s.push_back(i);
        }
        return res;
    }
};



int main()
{

    return 0;
}