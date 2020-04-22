// 199. 二叉树的右视图

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) return res;

        depth(root, res, 0);
        return res;
    }

    int depth(TreeNode* root, vector<int> &res, int i)
    {
        if (root == nullptr)
            return 1;

        if (res.empty() || i >= res.size())
            res.push_back(root->val);
        int right = depth(root->right, res, i + 1);
        int left = depth(root->left, res, i + 1);
        return max(right, left) + 1;
    }

    vector<int> rightSideView1(TreeNode* root)
    {
        vector<int> res;
        if (root == nullptr) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();   // 每一层的数量
            for (int i = 0; i < size; ++i)
            {
                TreeNode *tmp = q.front();
                q.pop();

                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
                if (i == size - 1) res.push_back(tmp->val);
            }
        }
        return res;
    }
};


int main()
{

    return 0;
}
