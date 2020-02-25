// 面试题32 - I. 从上到下打印二叉树

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> re;
        if (root == nullptr) return re;

        queue<TreeNode *> node;
        node.push(root);
        while (!node.empty())
        {
            root = node.front();
            node.pop();

            if (root == nullptr) continue;
            re.push_back(root->val);
            if (root->left) node.push(root->left);
            if (root->right) node.push(root->right);
        }
        return re;
    }
};

int main() {

    std::cout << endl;
    return 0;
}
