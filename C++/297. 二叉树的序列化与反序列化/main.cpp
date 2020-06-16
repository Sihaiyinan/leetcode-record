// 297. 二叉树的序列化与反序列化

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <queue>


using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "[]";
        queue<TreeNode*> q;
        q.push(root);
        vector<string> lists;

        while (!q.empty())
        {
            TreeNode *t = q.front();
            q.pop();
            if (t == nullptr)
            {
                lists.push_back("null");
                continue;
            }
            lists.push_back(to_string(t->val));
            q.push(t->left);
            q.push(t->right);
        }

        while (lists.back() == "null") lists.pop_back();
        string res = "[";
        for (const auto& s : lists)
        {
            res += s + ",";
        }
        res.pop_back();
        res += "]";
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty() || data.substr(1, 4) == "null"|| data == "[]") return nullptr;
        vector<string> lists;
        int l = 1;
        for (int i = 1; i < data.size(); ++i)
        {
            if (data[i] == ',' || data[i] == ']') {
                string t = data.substr(l, i - l);
                lists.push_back(t);
                l = i + 1;
            }
        }
        return vector2tree(lists);
    }

    TreeNode *vector2tree(vector<string> list)
    {
        int len = list.size();
        if (len == 0 || list[0] == "null") { return nullptr; }

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
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));



int main()
{
    vector<string> list = { "1", "2", "3", "null", "null", "4", "5" };
    auto l = Codec().vector2tree(list);
    string s = Codec().serialize(l);
    auto re = Codec().deserialize(s);


    return 0;
}