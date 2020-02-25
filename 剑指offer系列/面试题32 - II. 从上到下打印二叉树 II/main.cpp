// 面试题32 - II. 从上到下打印二叉树 II

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> re;
        if (root == nullptr) return re;

        queue<TreeNode *> node;
        node.push(root);
        int print_num = 1;    // 当前层待打印的结点个数
        int layer_num = 0;    // 下一层的结点个数
        vector<int> t;

        while (!node.empty())
        {
            root = node.front();
            node.pop();

            t.push_back(root->val);
            --print_num;

            if (root->left)
            {
                node.push(root->left);
                ++layer_num;
            }
            if (root->right)
            {
                node.push(root->right);
                ++layer_num;
            }
            if (0 == print_num)
            {
                re.push_back(t);
                t.clear();
                print_num = layer_num;
                layer_num = 0;
            }
        }
        return re;
    }
};

int main() {

    std::cout << endl;
    return 0;
}
