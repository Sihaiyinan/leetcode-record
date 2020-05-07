// 572. 另一个树的子树

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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr)
            return true;
        if (s == nullptr || t == nullptr)
            return false;

        if (bianli(s, t))
            return true;
        else
            return isSubtree(s->left, t) || isSubtree(s->right, t);
    }

    bool bianli(TreeNode *a, TreeNode *b)
    {
        if (a == nullptr && b == nullptr)
            return true;

        if (a == nullptr || b == nullptr)
            return false;

        if (a->val == b->val)
            return bianli(a->left, b->left) && bianli(a->right, b->right);
        else
            return false;
    }
};


int main()
{

    return 0;
}