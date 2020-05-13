// 102. 二叉树的层序遍历

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;

        vector<TreeNode *> q;
        q.push_back(root);
        res.push_back({q.front()->val});

        while (!q.empty())
        {
            vector<int> re;
            vector<TreeNode *> tmp;

            for (auto i : q)
            {
                if (i->left)
                {
                    re.push_back(i->left->val);
                    tmp.push_back(i->left);
                }
                if (i->right)
                {
                    re.push_back(i->right->val);
                    tmp.push_back(i->right);
                }
            }
            q = tmp;
            if (!q.empty())
                res.push_back(re);
        }
        return res;
    }
};


int main()
{

    return 0;
}