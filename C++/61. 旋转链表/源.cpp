// 61. 鏃嬭浆閾捐〃


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


ListNode *vector2list(const vector<int> &list)
{
	if (list.empty()) { return nullptr; }
	ListNode *root = new ListNode(0), *ptr = root;
	for (auto &i : list)
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
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == nullptr) return nullptr;
		if (head->next == nullptr) return head;

		ListNode *tmp = head;
		int len = 1;
		while (tmp->next)
		{
			tmp = tmp->next;
			++len;
		}
		tmp->next = head;
		k %= len;
		int i = 1;
		ListNode *ntrail = head;
		while (i < len - k)
		{
			ntrail = ntrail->next;
			++i;
		}
		ListNode *re = ntrail->next;
		ntrail->next = nullptr;
		return re;
	}
};

int main() {
	vector<int> list = { 1,2,3,4,5 };
	ListNode *node = vector2list(list);
	ListNode *re = Solution().rotateRight(node, 2);
	string slist = list2string(re);
	for (auto i : slist)
		cout << i << ' ';

	std::cout << endl;
	return 0;
}
