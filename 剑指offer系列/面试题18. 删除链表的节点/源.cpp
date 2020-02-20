// 面试题18. 删除链表的节点
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
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
	ListNode* deleteNode1(ListNode* head, int val) {
		if (head == nullptr) return head;

		ListNode *root = new ListNode(0);
		ListNode *pre = root;

		while (head)
		{
			if (head->val == val)
			{
				pre->next = head->next;
				break;
			}
			pre->next = head;
			pre = pre->next;
			head = head->next;
		}
		pre = root->next;
		delete root;
		return pre;
	}


	ListNode* deleteNode(ListNode* head, int val) {
		if (head == nullptr) return head;

		ListNode *pre = nullptr;
		ListNode *cur = head;

		while (cur && cur->val != val)
		{
			pre = cur;
			cur = cur->next;
		}
		if (cur == head) return cur->next;
		if (cur != nullptr) 
			pre->next = cur->next;
		return head;
	}
};

int main() 
{
	vector<int> a = {4,5,1,9 };
	ListNode *l1 = int2list(a);
	ListNode *re = Solution().deleteNode(l1, 2);
	cout << list2string(re) << endl;

	std::cout << endl;
	return 0;
}
