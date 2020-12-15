# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        def oneSideMax(root, ans):
            if root == None:
                return 0
            # oneSideMax(root.left, ans)[0]
            left = max(0, oneSideMax(root.left, ans))
            right = max(0, oneSideMax(root.right, ans))
            ans[0] = max(ans[0], left+right+root.val)
            return max(left, right) + root.val

        ans = [float('-inf')]
        oneSideMax(root, ans)
        return ans[0]