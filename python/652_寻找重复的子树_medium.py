# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        treeMap = collections.Counter()
        ans = []
        def deepTraverse(root):
            if not root:
                return '#'
            seq = '{},{},{}'.format(root.val, deepTraverse(root.left), deepTraverse(root.right))
            treeMap[seq] += 1
            if treeMap[seq] == 2:
                ans.append(root)
            return seq
        deepTraverse(root)
        return ans