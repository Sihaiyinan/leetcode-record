// 面试题55 - II. 平衡二叉树

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <functional>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if (root == nullptr)
			return true;
		int flag = depth(root);
		return flag != -1 ? true : false;
	}

	int depth(TreeNode *root)
	{
		if (root == nullptr)
			return 0;
		int left = depth(root->left);
		if (left == -1) return -1;
		int right = depth(root->right);
		if (right == -1) return -1;
		if (abs(left - right) > 1)
			return -1;
		return max(left, right) + 1;
	}
};

int main()
{

	std::cout << std::endl;
	return 0;
}