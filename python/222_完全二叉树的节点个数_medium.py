# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# 法一：递归

class Solution:
    def countNodes(self, root: TreeNode) -> int:
        def subcount(root):
            if not root:
                return 0
            return 1 + subcount(root.left) + subcount(root.right)
        return subcount(root)