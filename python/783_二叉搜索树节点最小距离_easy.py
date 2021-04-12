# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDiffInBST(self, root: TreeNode) -> int:
        self.pre, self.ans = -1, float('+inf')
        def DFS(root):
            if not root:
                return
            DFS(root.left)
            if self.pre != -1:
                self.ans = min(self.ans, root.val-self.pre)
            self.pre = root.val
            DFS(root.right)
        DFS(root)
        return self.ans