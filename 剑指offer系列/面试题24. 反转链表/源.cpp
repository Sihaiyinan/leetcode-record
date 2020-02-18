// 面试题24. 反转链表

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
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr) return head;
		ListNode *pre = head;
		ListNode *cur = head;
		ListNode *next = head->next;

	}
};

int main() 
{

	std::cout << endl;
	return 0;
}
