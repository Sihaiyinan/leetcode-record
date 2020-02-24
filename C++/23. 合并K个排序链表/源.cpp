// 23. 合并K个排序链表


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
	ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
	{
		ListNode *cur_ptr = new ListNode(0), *head = cur_ptr;
		while (list1 && list2)
		{
			if (list1->val < list2->val)
			{
				cur_ptr->next = list1;
				list1 = list1->next;
			}
			else
			{
				cur_ptr->next = list2;
				list2 = list2->next;
			}
			cur_ptr = cur_ptr->next;
		}
		if (list1)
			cur_ptr->next = list1;
		else
			cur_ptr->next = list2;
		cur_ptr = head->next;
		delete head;
		return cur_ptr;
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.empty()) return nullptr;
		if (lists.size() == 1)return lists[0];

		ListNode *tmp = lists[0];
		for (int i = 1; i < lists.size(); ++i)
			tmp = mergeTwoLists(tmp, lists[i]);
		return tmp;
	}
};

int main() 
{
	vector<int> l1, l2, l3;
	l1 = { 1, 4, 5 };
	l2 = { 1, 3, 4 };
	l3 = { 2, 6 };

	vector<ListNode *> lists = { int2list(l1), int2list(l2), int2list(l3) };
	ListNode *re = Solution().mergeKLists(lists);
	string slist = list2string(re);
	for (auto i : slist)
		cout << i << ' ';

	std::cout << endl;
	return 0;
}
