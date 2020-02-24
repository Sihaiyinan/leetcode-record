// 面试题22. 链表中倒数第k个节点

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
	ListNode* getKthFromEnd(ListNode* head, int k) {
		if (head == nullptr) return nullptr;
		ListNode *fast = head, *slow = head;
		int count = 0;
		while (count < k && fast)
		{
			fast = fast->next;
			++count;
		}
		if (count < k) return nullptr;
		while (fast)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
};

int main() 
{

	std::cout << endl;
	return 0;
}
