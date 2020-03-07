// 面试题52. 两个链表的第一个公共节点

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;

        int lenA = 0, lenB = 0;
        ListNode *tA = headA, *tB = headB, *re;
        // 首先计算两个链表的长度
        while (tA != nullptr)
        {
            ++lenA;
            tA = tA->next;
        }
        while (tB != nullptr)
        {
            ++lenB;
            tB = tB->next;
        }
        int k = 0;
        if (lenA > lenB)
        {
            tA = headA;
            tB = headB;
            k = lenA - lenB;
        } else
        {
            tA = headB;
            tB = headA;
            k = lenB - lenA;
        }
        // k为两个链表的差值，让长的链表先走k步
        while (k)
        {
            tA = tA->next;
            --k;
        }
        while (tA != nullptr && tB != nullptr)
        {
            if (tA == tB)
            {
                re = tA;
                break;
            }
            tA = tA->next;
            tB = tB->next;
        }
        return re;
    }
};

int main() {

    std::cout << std::endl;
    return 0;
}
