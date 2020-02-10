"""
104. 二叉树的最大深度
"""

def list2tree(input):
    if len(input) == 0:
        return None

    root = TreeNode(input[0])
    nodeQueue = [root]
    front = 0
    index = 1
    while index < len(input):
        node = nodeQueue[front]
        front += 1

        item = input[index]
        index += 1
        if item != "null":
            node.left = TreeNode(item)
            nodeQueue.append(node.left)

        if index >= len(input): break
        item = input[index]
        index += 1
        if item != "null":
            node.right = TreeNode(item)
            nodeQueue.append(node.right)

    return root


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root: return 0;
        return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1


a = [3,9,20,"null","null",15,7]
print(Solution().maxDepth(list2tree(a)))



