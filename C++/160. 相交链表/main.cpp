// 160. 相交链表

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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == nullptr || headB == nullptr) return nullptr;
		ListNode *l1, *l2, *res = nullptr;
		l1 = headA;
		l2 = headB;
		int len1 = 0, len2 = 0;
		while (l1)
		{
			++len1;
			l1 = l1->next;
		}
		while (l2)
		{
			++len2;
			l2 = l2->next;
		}

		if (len1 >= len2)
		{
			int gap = len1 - len2;
			l1 = headA;
			while (gap--)
			{
				l1 = l1->next;
			}
			l2 = headB;
			while (l1 != l2)
			{
				l1 = l1->next;
				l2 = l2->next;
			}
			res = l1;
		}
		else
		{
			int gap = len2 - len1;
			l1 = headB;
			while (gap--)
			{
				l1 = l1->next;
			}
			l2 = headA;
			while (l1 != l2)
			{
				l1 = l1->next;
				l2 = l2->next;
			}
			res = l1;
		}
		return res;
	}
};

int main()
{


	return 0;
}