// 面试题28. 对称的二叉树
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == nullptr) return true;
		return bianli(root, root);
	}

	bool bianli(TreeNode *left, TreeNode *right)
	{
		if (left == nullptr && right == nullptr)
			return true;
		if (left == nullptr || right == nullptr)
			return false;
		if (left->val != right->val)
			return false;
		return bianli(left->left, right->right) && bianli(left->right, right->left);
	}
};

int main() 
{

	std::cout << endl;
	return 0;
}
