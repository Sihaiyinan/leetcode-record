// 104. 二叉树的最大深度


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *vector2tree(vector<string> list) 
{
	int len = list.size();
	if (len == 0) { return nullptr; }

	TreeNode* root = new TreeNode(stoi(list[0]));
	vector<TreeNode*> nodeQueue;
	nodeQueue.push_back(root);

	int front = 0, index = 1;
	string item;
	while (index < len)
	{
		TreeNode *node = nodeQueue[front];
		front += 1;

		item = list[index];
		index += 1;
		if (item != "null")
		{
			node->left = new TreeNode(stoi(item));
			nodeQueue.push_back(node->left);
		}

		if (index >= len) { break; }

		item = list[index];
		index += 1;
		if (item != "null")
		{
			node->right = new TreeNode(stoi(item));
			nodeQueue.push_back(node->right);
		}
	}

	return root;
}


class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == nullptr) { return 0; }
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};

int main() {
	vector<string> list = { "3", "9", "20", "null", "null", "15", "7" };
	int re = Solution().maxDepth(vector2tree(list));
	std::cout << re;


	std::cout << endl;
	return 0;
}
