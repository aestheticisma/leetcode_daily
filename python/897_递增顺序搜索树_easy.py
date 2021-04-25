# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.dummyHead = TreeNode()
        self.cur = self.dummyHead
    def increasingBST(self, root: TreeNode) -> TreeNode:
        def inorder(node):
            if not node:
                return
            inorder(node.left)
            self.cur.right = node
            node.left = None
            self.cur = node
            inorder(node.right)
        inorder(root)
        return self.dummyHead.right