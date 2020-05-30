// 84. 柱状图中最大的矩形

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    /**
     * 暴力法， 枚举宽度（超时）
     */
    int largestRectangleArea1(vector<int>& heights) {
        int res = 0;

        for (int i = 0; i < heights.size(); ++i)
        {
            int min_h = INT_MAX;
            for (int j = i; j < heights.size(); ++j)
            {
                min_h = min(min_h, heights[j]);
                res = max(res, (j - i + 1) * min_h);
            }
        }
        return res;
    }

    /**
     * 暴力法，枚举高度（超时）
     * 以每一条高度为中心，向两边扩散
     */
    int largestRectangleArea2(vector<int>& heights) {
        int res = 0;

        for (int i = 0; i < heights.size(); ++i)
        {
            int l = i, r = i;
            while (l > 0 && heights[l - 1] >= heights[i])
                --l;
            while (r + 1 < heights.size() && heights[r + 1] >= heights[i])
                ++r;
            res = max(res, (r - l + 1) * heights[i]);
        }

        return res;
    }

    /**
     * 单调栈，预设两个数组left和right统计每一个柱子能到达的最远距离
     */
    int largestRectangleArea(vector<int>& heights) {
        int res = 0, n = heights.size();
        vector<int> left(n), right(n);

        stack<int> s;
        for (int i = 0; i < heights.size(); ++i)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            left[i] = (s.empty() ? -1 : s.top());
            s.push(i);
        }

        s = stack<int>();
        for (int i = n - 1; i >= 0; --i)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            right[i] = (s.empty() ? n : s.top());
            s.push(i);
        }

        for (int i = 0; i < n; ++i)
            res = max(res, (right[i] - left[i] - 1) * heights[i]);

        return res;
    }
};

int main()
{

    return 0;
}