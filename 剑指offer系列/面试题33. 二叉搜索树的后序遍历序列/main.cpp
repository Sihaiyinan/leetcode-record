// 面试题33. 二叉搜索树的后序遍历序列

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.empty()) return true;
        return bianli(postorder, 0, postorder.size() - 1);
    }

    bool bianli(vector<int> &postorder, int begin, int end)
    {
        if (begin >= end) return true;

        int i = begin, j = end - 1;
        while (i < end && postorder[i] < postorder[end])
            ++i;

        while (j >= begin && postorder[j] > postorder[end])
            --j;

        if (i < j)
            return false;

        bool left = bianli(postorder, begin, i - 1);
        bool right = bianli(postorder, j + 1, end - 1);
        return left && right;
    }
};

int main() {
    vector<int> a = {9,11,10,2};
    cout << Solution().verifyPostorder(a) << endl;


    std::cout << std::endl;
    return 0;
}
