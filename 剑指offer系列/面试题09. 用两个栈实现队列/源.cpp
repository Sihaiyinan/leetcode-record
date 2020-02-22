// 面试题09. 用两个栈实现队列

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
	TreeNode *constructCore(
		vector<int> &preorder, int pre_begin, int pre_end,
		vector<int> &inorder, int in_begin, int in_end)
	{
		int val = preorder[pre_begin];
		TreeNode *root = new TreeNode(val);

		int pos = in_begin;         // 记录前序遍历中的根结点在中序遍历中的位置
		while (inorder[pos] != val)
			++pos;

		int left_size = pos - in_begin;
		int right_size = in_end - in_begin - left_size;

		if (left_size > 0)
			root->left = constructCore(preorder, pre_begin + 1, pre_begin + left_size, 
				inorder, in_begin, in_begin + left_size - 1);
		if (right_size > 0)
			root->right = constructCore(preorder, pre_begin + left_size + 1, pre_end,
				inorder, pos + 1, in_end);
		
		return root;
	}

	/*
	前序遍历的第一位是根结点， 中序遍历根节点右侧的都是右子树，左侧都是左子树；
	分别计算出左右子树的位置进行递归。
	**/
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.empty() || inorder.empty())
			return nullptr;
		return constructCore(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}
};

int main() 
{


	std::cout << endl;
	return 0;
}
