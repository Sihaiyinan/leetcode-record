// 24. 两两交换链表中的节点

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct ListNode
{
	int val; 
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr) return head;
		if (head->next == nullptr) return head;

		ListNode *root = new ListNode(0);
		root->next = head;
		ListNode *p = root;

		ListNode *a = head, *b = head->next;


		while (b->next && b->next->next)
		{
			a->next = b->next;
			b->next = a;
			p->next = b;

			ListNode *t = a;
			a = b;
			b = t;

			p = b;
			a = a->next->next;
			b = b->next->next;
		}

		a->next = b->next;
		b->next = a;
		p->next = b;

		p = root->next;
		delete root;
		return p;
	}
};


int main()
{

	return 0;
}