"""
61. 旋转链表
"""

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def vector2list(v):
    if len(v) == 0: return None
    root = ListNode(0)
    ptr = root
    for i in v:
        ptr.next = ListNode(i)
        ptr = ptr.next
    ptr = root.next
    return ptr

def list2string(List):
    if not List:
        return "[]"
    res = ""
    while List:
        res += str(List.val) + " "
        List = List.next
    return "[" + res[:-1] + ']'


class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head: return None
        if not head.next: return head
        ptr = head
        size = 1
        while ptr.next:
            ptr = ptr.next
            size += 1
        ptr.next = head   # 连接首尾
        k %= size
        nhead = head
        i = 1
        while i < size - k:
            nhead = nhead.next
            i += 1
        re = nhead.next
        nhead.next = None
        return re


a = [1, 2, 3, 4, 5]
re = Solution().rotateRight(vector2list(a), 2)
print(list2string(re))



