// 面试题06. 从尾到头打印链表


#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {};
};

ListNode *vector2list(vector<int> v)
{
	if (v.empty()) return nullptr;
	ListNode *root = new ListNode(0);
	ListNode *ptr = root;
	
	for (auto &i : v)
	{
		ptr->next = new ListNode(i);
		ptr = ptr->next;
	}
	ptr = root->next;
	delete root;
	return ptr;
}

class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		vector<int> re, rre;
		while (head)
		{
			re.push_back(head->val);
			head = head->next;
		}
		for (int i = re.size() - 1; i >= 0; --i)
		{
			rre.push_back(re[i]);
		}
		return rre;
	}
};

int main() 
{


	std::cout << endl;
	return 0;
}
