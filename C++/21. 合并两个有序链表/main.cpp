#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *int2list(const vector<int>& nums)
{
	ListNode *root = new ListNode(0);
	ListNode *ptr = root;
	for (auto &i : nums)
	{
		ptr->next = new ListNode(i);
		ptr = ptr->next;
	}
	ptr = root->next;
	delete root;
	return ptr;
}

string list2string(ListNode *node)
{
	if (node == nullptr)
		return string("");
	string re = "";
	while (node)
	{
		re += to_string(node->val) + " ";
		node = node->next;
	}
	re.pop_back();
	return re;
}
 
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		// 递归
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;

		if (l1->val < l2->val)
		{
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else
		{
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}

	ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
		// 迭代
		ListNode *head = new ListNode(0);
		ListNode *cur = head;

		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				cur->next = l1;
				l1 = l1->next;
			}
			else
			{
				cur->next = l2;
				l2 = l2->next;
			}
			cur = cur->next;
		}
		l1 ? cur->next = l1 : cur->next = l2;
		cur = head->next;
		delete head;
		return cur;
	}
};


int main()
{
	vector<int> a = { 1, 2, 4 };
	vector<int> b = { 1, 3, 4 };
	ListNode *l1 = int2list(a);
	ListNode *l2 = int2list(b);
	ListNode *re = Solution().mergeTwoLists2(l1, l2);
	cout << list2string(re) << endl;

	return 0;
}