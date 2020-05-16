// 25. K 个一组翻转链表

#include <iostream>
#include <vector>

using namespace std;

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


class Solution {
public:
    // 输入一段结点的头结点和尾结点，返回翻转后的头结点和尾结点
    vector<ListNode*> reverseList(ListNode* left, ListNode* right)
    {
        if (left == nullptr) return {left, left};
        ListNode* pre = nullptr, *cur = left, *next = cur->next;

        while (next != right)
        {
            cur->next = pre;
            pre = cur;
            cur = next;
            next = next->next;
        }
        cur->next = pre;
        next->next = cur;
        return {next, left};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) return head;
        ListNode* left = head, *right = head;
        ListNode* root = new ListNode(0);
        ListNode* cur = root;

        if (k == 1) return head;   // 如果 k == 1 直接返回

        while (right)
        {
            int flag = 0;
            for (int i = 0; i < k - 1; ++i)
            {
                if (right->next)
                    right = right->next;
                else  // 如果没循环到k次结束直接break
                {
                    flag = 1;
                    break;
                }
            }
            ListNode *t = nullptr;
            if (flag == 0)  t = right->next;   // 让 t 指向下一个结点
            if (flag == 1) break;
            auto tmp = reverseList(left, right);
            cur->next = tmp[0];
            left = t;
            right = t;
            cur = tmp[1];
        }
        cur->next = left;
        cur = root->next;
        delete root;
        return cur;
    }
};

int main()
{
    vector<int> nums = {1,2,3,4,5};
    int k = 2;
    ListNode *res = Solution().reverseKGroup(int2list(nums), k);

    return 0;
}