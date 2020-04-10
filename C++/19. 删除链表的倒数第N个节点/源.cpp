// 19. 删除链表的倒数第N个节点

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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *first, *second;
		first = head; second = head;
		for (int i = 0; i < n; ++i)
		{
			second = second->next;
		}
		if (second == NULL)
			return head->next;
		while (second->next != NULL)
		{
			first = first->next;
			second = second->next;
		}
		first->next = first->next->next;
		return head;
	}
};


int main()
{


	return 0;
}