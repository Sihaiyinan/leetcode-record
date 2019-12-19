# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        """
        先进行链表相加,然后在对每一位进行判断,效率不高
        """
        re = ListNode(0)
        r = re
        while l1 and l2:
            r.next = ListNode(l1.val + l2.val)
            r = r.next
            l1 = l1.next
            l2 = l2.next
        r.next = l1 if l1 else l2
        return carry_judge(re.next)

def carry_judge(l):
    if l is None:
        return l
    flag = 0
    cur = l
    while cur.next:
        if flag:
            cur.val += 1
            flag = 0
        if cur.val > 9:
            cur.val -= 10
            flag = 1
        cur = cur.next
    if flag:
        cur.val += 1
    if cur.val > 9:
        cur.val -= 10
        cur.next = ListNode(1)
    return l


def List2ListNode(inputs):
    dummyRoot = ListNode(0)
    ptr = dummyRoot
    for i in inputs:
        ptr.next = ListNode(i)
        ptr = ptr.next
    ptr = dummyRoot.next
    return ptr

def ListNode2List(node):
    if not node:
        return "[]"
    result = ""
    while node:
        result += str(node.val) + ", "
        node = node.next
    return "[" + result[:-2] + "]"

if __name__ == '__main__':
    l1 = [2, 3]
    l2 = [5, 6, 4]
    L1 = List2ListNode(l1)
    L2 = List2ListNode(l2)
    re = Solution().addTwoNumbers(L1, L2)
    print(l1)
    print(l2)
    print(ListNode2List(re))



