// 148. 排序链表

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
	static int compare(const void *a, const void *b)
	{
		return *(int *)a - *(int *)b;
	}

	ListNode* sortList(ListNode* head) {
		if (head == nullptr) return head;
		vector<int> l;

		ListNode *tmp = head;
		while (tmp)
		{
			l.push_back(tmp->val);
			tmp = tmp->next;
		}

		qsort(l.data(), l.size(), sizeof(int), compare);
		tmp = head;
		for (auto i : l)
		{
			tmp->val = i;
			tmp = tmp->next;
		}
		return head;
	}
};

int main()
{

	return 0;
}