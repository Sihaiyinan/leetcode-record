// 面试题27. 二叉树的镜像
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
	TreeNode* mirrorTree(TreeNode* root) {
		if (root == nullptr) return root;

		TreeNode *tmp = root->left;
		root->left = mirrorTree(root->right);
		root->right = mirrorTree(tmp);
		return root;
	}
};

int main() 
{

	std::cout << endl;
	return 0;
}
