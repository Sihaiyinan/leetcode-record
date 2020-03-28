// 230. 二叉搜索树中第K小的元素

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
	int flag = 0;
	int kthSmallest(TreeNode* root, int k) {
		int val = 0;
		int cur = 0;
		bianli(root, k, cur, val);
		return val;
	}

	void bianli(TreeNode *root, int k, int &cur, int &val)
	{
		if (root == nullptr) return;
		bianli(root->left, k, cur, val);
		if (flag == 1) return;
		++cur;
		if (cur == k) {
			val = root->val;
			flag = 1;
			return;
		}
		bianli(root->right, k, cur, val);
	}
};

int main()
{


	return 0;
}