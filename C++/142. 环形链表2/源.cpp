// 104. ª∑–Œ¡¥±Ì2


#include <iostream>
#include <vector>
#include <string>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode *fast = head, *slow = head;
		while (true)
		{
			if (fast == nullptr || fast->next == nullptr) return NULL;
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow) break;
		}
		fast = head;
		while (fast != slow)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return fast;
	}
};

int main() 
{


	std::cout << endl;
	return 0;
}
