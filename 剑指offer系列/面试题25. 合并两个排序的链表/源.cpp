// 面试题25. 合并两个排序的链表

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;

		ListNode *root = new ListNode(0);
		ListNode *ptr = root;

		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				ptr->next = l1;
				l1 = l1->next;
			}
			else
			{
				ptr->next = l2;
				l2 = l2->next;
			}
			ptr = ptr->next;
		}
		if (l1 == nullptr)
			ptr->next = l2;
		if (l2 == nullptr)
			ptr->next = l1;
		ptr = root->next;
		delete root;
		return ptr;
	}
};

int main() 
{

	std::cout << endl;
	return 0;
}
