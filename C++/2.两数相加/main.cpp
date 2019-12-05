#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *re = new ListNode(0);
        ListNode *r = re;
        r = re;
        while (l1 && l2) {
            r->next = new ListNode(l1->val + l2->val);
            r = r->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 == nullptr)
            r->next = l2;
        else
            r->next = l1;
        r = re->next;
        delete re;
        return carry_judge(r);
    }

    static ListNode* carry_judge(ListNode *list) {
        if (list == nullptr)
            return list;
        int flag = 0;
        ListNode *cur = list;
        while (cur->next != nullptr) {
            if (flag) {
                cur->val += 1;
                flag = 0;
            }
            if (cur->val > 9) {
                cur->val -= 10;
                flag = 1;
            }
            cur = cur->next;
        }
        if (flag)
            cur->val += 1;
        if (cur->val > 9) {
            cur->val -= 10;
            cur->next = new ListNode(1);
        }
        return list;
    }
};


ListNode* vector2ListNode(vector<int> list) {
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;

    for (auto i : list) {
        ptr->next = new ListNode(i);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

vector<int> ListNode2vector(ListNode* node) {
    vector<int> re;
    if (node == nullptr)
        return re;

    while (node) {
        re.push_back(node->val);
        node = node->next;
    }
    return re;
}

int main()
{
    vector<int> l1 = {2, 4, 3};
    vector<int> l2 = {5, 6, 4};
    ListNode *L1 = vector2ListNode(l1);
    ListNode *L2 = vector2ListNode(l2);
    vector<int> re = ListNode2vector(Solution().addTwoNumbers(L1, L2));
    for (auto i : re)
        cout << i << endl;
    return 0;
}