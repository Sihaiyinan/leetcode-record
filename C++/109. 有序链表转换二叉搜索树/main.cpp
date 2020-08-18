// 109. 有序链表转换二叉搜索树

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>


using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    vector<int> list2vec(ListNode *head)
    {
        vector<int> res;
        while (head)
        {
            res.push_back(head->val);
            head = head->next;
        }
        return res;
    }

    TreeNode* build_tree(vector<int> &nums, int l, int r)
    {
        if (l == r) return nullptr;
        int mid = l + (r - l) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = build_tree(nums, l, mid);
        root->right = build_tree(nums, mid + 1, r);
        return root;
    }


    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        auto nums = list2vec(head);
//        vector<int> nums = {-10, -3, 0, 5, 9};
        return build_tree(nums, 0, nums.size());
    }
};



int main()
{
    auto re = Solution().sortedListToBST(nullptr);

    return 0;
}

