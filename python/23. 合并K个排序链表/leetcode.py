"""
23. 合并K个排序链表
"""

from typing import List

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def int2list(numbers):
    numbers = list(map(int, numbers))
    root = ListNode(0)
    ptr = root
    for number in numbers:
        ptr.next = ListNode(number)
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
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        cur_ptr = ListNode(0)
        head = cur_ptr

        while l1 and l2:
            if l1.val < l2.val:
                cur_ptr.next = l1
                l1 = l1.next
            else:
                cur_ptr.next = l2
                l2 = l2.next
            cur_ptr = cur_ptr.next

        cur_ptr.next = l1 if l1 is not None else l2
        return head.next


    def mergeKLists1(self, lists: List[ListNode]) -> ListNode:
        if lists.__len__() == 0: return None
        if lists.__len__() == 1: return lists[0]

        tmp = lists[0]
        for i in lists[1:]:
            tmp = self.mergeTwoLists(tmp, i)
        return tmp

    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        nodes = []
        for i in lists:
            while i:
                nodes.append(i.val)
                i = i.next
        root = ListNode(0)
        tmp = root
        sorted_nodes = sorted(nodes)
        for i in sorted_nodes:
            tmp.next = ListNode(i)
            tmp = tmp.next
        return root.next


l1 = [1, 4, 5]
l2 = [1, 3, 4]
l3 = [2, 6]

list1 = int2list(l1)
list2 = int2list(l2)
list3 = int2list(l3)
Lists = [list1, list2, list3]
re = Solution().mergeKLists(Lists)
print(list2string(re))
