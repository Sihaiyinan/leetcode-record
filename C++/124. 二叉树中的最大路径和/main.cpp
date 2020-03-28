// 124. 二叉树中的最大路径和

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	int maxPathSum(TreeNode* root) {
		if (root == nullptr) return 0;
		int maxc = 0x80000000;
		bianli(root, maxc);
		return maxc;
	}

	int bianli(TreeNode *root, int &maxc)
	{
		if (root == nullptr) return 0;
		int left = max(0, bianli(root->left, maxc));
		int right = max(0, bianli(root->right, maxc));
		int tmp = left + right + root->val;
		if (tmp > maxc) maxc = tmp;
		return max(left, right) + root->val;
	}
};

int main()
{

	return 0;
}