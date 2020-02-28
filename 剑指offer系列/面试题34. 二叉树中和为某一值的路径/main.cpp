// 面试题34. 二叉树中和为某一值的路径

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *vector2tree(vector<string> list)
{
    int len = list.size();
    if (len == 0) { return nullptr; }

    TreeNode* root = new TreeNode(stoi(list[0]));
    vector<TreeNode*> nodeQueue;
    nodeQueue.push_back(root);

    int front = 0, index = 1;
    string item;
    while (index < len)
    {
        TreeNode *node = nodeQueue[front];
        front += 1;

        item = list[index];
        index += 1;
        if (item != "null")
        {
            node->left = new TreeNode(stoi(item));
            nodeQueue.push_back(node->left);
        }

        if (index >= len) { break; }

        item = list[index];
        index += 1;
        if (item != "null")
        {
            node->right = new TreeNode(stoi(item));
            nodeQueue.push_back(node->right);
        }
    }

    return root;
}

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> re;
        if (root == nullptr) return re;
        vector<int> tmp;
        bfs(root, 0, sum, re, tmp);
        return re;
    }

    int bfs(TreeNode *root, int cur_sum, int &sum, vector<vector<int>> &res, vector<int> &re)
    {
        if (root == nullptr) return 0;
        if (root->val + cur_sum > sum)
        {
            return 0;
        }
        if (root->val + cur_sum == sum && root->left == nullptr && root->right == nullptr)
        {
            re.push_back(root->val);
            res.push_back(re);
            re.pop_back();
            return 0;
        }
        if (root->val + cur_sum < sum)
        {
            re.push_back(root->val);
            bfs(root->left, cur_sum + root->val, sum, res, re);
            bfs(root->right, cur_sum + root->val, sum, res, re);
            re.pop_back();
        }
        return 0;
    }
};

int main() {
    vector<string> list = {"1", "2"};//{ "5","4","8","11","null","13","4","7","2","null","null","5","1" };
    vector<vector<int>> re = Solution().pathSum(vector2tree(list), 1);

    for (auto &i : re) {
        for (auto &j : i)
            cout << j << ' ';
        cout << endl;
    }
    std::cout << std::endl;
    return 0;
}
