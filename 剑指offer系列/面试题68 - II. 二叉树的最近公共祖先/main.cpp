// 面试题68 - II. 二叉树的最近公共祖先

#include <iostream>
#include <vector>
#include <string>

using namespace std;



struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr || root == q || root == p)
			return root;

		auto left = lowestCommonAncestor(root->left, p, q);
		auto right = lowestCommonAncestor(root->right, p, q);

		if (left == nullptr)
			return right;
		if (right == nullptr)
			return left;
		return root;
	}
};

int main()
{


	std::cout << std::endl;
	return 0;
}