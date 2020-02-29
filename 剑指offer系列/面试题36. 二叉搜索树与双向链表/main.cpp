// 面试题36. 二叉搜索树与双向链表

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) return root;
        Node *pLastNode = nullptr;
        tree2list(root, &pLastNode);
        Node *pHeadNode = pLastNode;
        while (pHeadNode != nullptr && pHeadNode->left != nullptr)
            pHeadNode = pHeadNode->left;
        pLastNode->right = pHeadNode;
        pHeadNode->left = pLastNode;
        return pHeadNode;
    }

    void tree2list(Node *root, Node **ptr)
    {
        if (root == nullptr) return;
        if (root->left != nullptr)
            tree2list(root->left, ptr);

        root->left = *ptr;
        if (*ptr != nullptr)
            (*ptr)->right = root;
        *ptr = root;

        if (root->right != nullptr)
            tree2list(root->right, ptr);
    }
};

int main() {
    

    std::cout << std::endl;
    return 0;
}
