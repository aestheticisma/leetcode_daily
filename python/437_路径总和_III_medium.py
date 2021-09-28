# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: TreeNode, targetSum: int) -> int:
        prefix = defaultdict(int)
        prefix[0] = 1
        def dfs(root, curr):
            if not root:
                return 0
            res = 0
            curr += root.val
            if curr-targetSum in prefix:
                res += prefix[curr-targetSum]
            prefix[curr] += 1
            res += dfs(root.left, curr)
            res += dfs(root.right, curr)
            prefix[curr] -= 1
            return res
        return dfs(root, 0)