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
	/*
	思路：
	第一步，首先在A中查找与根结点相同的结点
	第二步，如果结点相同，判断其是否为子树
	**/
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		if (A == nullptr || B == nullptr)
			return false;

		if (A->val == B->val)
			return sub_tree(A, B);
		else
			return isSubStructure(A->left, B) || isSubStructure(A->right, B);
	}

	bool sub_tree(TreeNode *A, TreeNode *B)
	{
		if (B == nullptr)
			return true;
		if (A == nullptr)
			return false;
		if (A->val != B->val)
			return false;
		return sub_tree(A->left, B->left) && sub_tree(A->right, B->right);
	}
};

int main() 
{

	std::cout << endl;
	return 0;
}
