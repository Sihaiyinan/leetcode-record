// 面试题37. 序列化二叉树

#include <iostream>
#include <vector>
#include <string>
#include <queue>

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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string re;
        if (root == nullptr) return re;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *tmp = q.front();
            q.pop();
            if (tmp == nullptr)
            {
                re += "null ";
                continue;
            }
            re += to_string(tmp->val) + " ";
            q.push(tmp->left);
            q.push(tmp->right);
        }
        return re;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> s = split(data, ' ');
        if (s.empty()) return nullptr;

        queue<TreeNode *> q;
        int index = 0;
        TreeNode *root = new TreeNode(atoi(s[index].c_str()));
        ++index;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *tmp = q.front();
            q.pop();
            if (index >= s.size()) break;
            if (s[index] != "null")
            {
                tmp->left = new TreeNode(atoi(s[index].c_str()));
                q.push(tmp->left);
            }
            ++index;
            if (index >= s.size()) break;
            if (s[index] != "null")
            {
                tmp->right = new TreeNode(atoi(s[index].c_str()));
                q.push(tmp->right);
            }
            ++index;
        }
        return root;
    }

    vector<string> split(const string &s, char c)
    {
        vector<string> re;
        if (s.empty()) return re;

        string tmp;
        for (auto &i : s)
        {
            if (i != c)
                tmp.push_back(i);
            else
            {
                re.push_back(tmp);
                tmp.clear();
            }
        }
        if (!tmp.empty())
            re.push_back(tmp);
        return re;
    }
};

int main() {
    vector<string> v = {"1","2","3","null","null","4","5"};
    TreeNode *tree = vector2tree(v);
    TreeNode *re = Codec().deserialize(Codec().serialize(tree));

    std::cout << std::endl;
    return 0;
}
