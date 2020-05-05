// 98. 验证二叉搜索树

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long max_val = LONG_MIN;
        return dfs(root, max_val);
    }

    bool dfs(TreeNode* root, long &max_val)
    {
        if (root == nullptr)
            return true;

        bool left = dfs(root->left, max_val);
        if (root->val <= max_val)
            return false;
        else
            max_val = root->val;
        bool right = dfs(root->right, max_val);
        return left && right;
    }
};


int main()
{

    return 0;
}