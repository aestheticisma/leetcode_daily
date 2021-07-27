# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.ans = -1
    
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        rootVal = root.val
        def dfs(root):
            if not root:
                return
            if self.ans != -1 and root.val >= self.ans:
                return
            if root.val > rootVal:
                self.ans = root.val
            dfs(root.left)
            dfs(root.right)
        dfs(root.left)
        dfs(root.right)
        return self.ans
