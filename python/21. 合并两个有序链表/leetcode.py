
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
	"""
	递归
	"""
	def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
		if l1 is None:
			return l2
		if l2 is None:
			return l1
		if l1.val < l2.val:
			l1.next = self.mergeTwoLists(l1.next, l2)
			return l1
		else:
			l2.next = self.mergeTwoLists(l1, l2.next)
			return l2

	def mergeTwoLists2(self, l1: ListNode, l2: ListNode) -> ListNode:
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


if __name__ == '__main__':
	a = [1, 2, 4]
	b = [1, 3, 4]
	lista = int2list(a)
	listb = int2list(b)
	re = Solution().mergeTwoLists2(lista, listb)
	print(list2string(re))


