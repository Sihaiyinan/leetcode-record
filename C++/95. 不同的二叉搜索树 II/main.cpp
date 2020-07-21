// 95. 不同的二叉搜索树 II

#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if (n == 0) return res;

        return bianli(1, n);
    }

    vector<TreeNode*> bianli(int l, int r)
    {
        if (l > r) return {nullptr};

        vector<TreeNode*> res;

        // 枚举可行的根结点
        for (int i = l; i <= r; ++i)
        {
            // 获得所有可行的左子树集合
            vector<TreeNode*> leftTree = bianli(l, i - 1);

            // 获得所有可行的右子树集合
            vector<TreeNode*> rightTree = bianli(i + 1, r);

            // 以当前结点为根结点，从左右子树中选取可行解
            for (auto &left : leftTree)
            {
                for (auto &right : rightTree)
                {
                    TreeNode *tmp = new TreeNode(i);
                    tmp->left = left;
                    tmp->right = right;
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};



int main() {


    return 0;
}