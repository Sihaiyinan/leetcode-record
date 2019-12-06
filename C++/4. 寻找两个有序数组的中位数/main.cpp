#include <iostream>
#include <vector>

using namespace std;

int compare (const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//        不满足题目要求
        for (auto i : nums2) nums1.push_back(i);
        qsort(nums1.data(), nums1.size(), sizeof(int), compare);
        int size = nums1.size();
        if (size % 2 == 0)
            return (nums1[size/2 - 1] + nums1[size/2]) / 2.0;
        else
            return nums1[size/2] * 1.0;
    }
};

int main()
{
    vector<int>a, b;
    a = {1, 2};
    b = {3, 4};
    cout << Solution().findMedianSortedArrays(a, b) << endl;
    return 0;
}