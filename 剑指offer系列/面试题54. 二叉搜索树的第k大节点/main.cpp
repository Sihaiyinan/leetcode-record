// 面试题54. 二叉搜索树的第k大节点

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
	int kthLargest(TreeNode* root, int k) {
		if (root == nullptr)
			return 0;
		// priority_queue<int, vector<int>, greater<int>> q;
		int val, num = 0;
		bianli(root, k, num, val);
		return val;
	}

	int bianli(TreeNode *root, int k, int &num, int &re)
	{
		if (root == nullptr)
			return 0;
		bianli(root->right, k, num, re);
		if (++num == k)
		{
			re = root->val;
			return 0;
		}
		bianli(root->left, k, num, re);
		return 0;
	}
};

int main()
{

	std::cout << std::endl;
	return 0;
}