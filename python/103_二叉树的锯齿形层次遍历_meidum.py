# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        stack = [root]
        ans, left = [], True
        while stack:
            # current = stack.pop()
            num = len(stack)
            tmp = []
            for i in range(num):
                current = stack.pop(0)
                if left:
                    tmp.append(current.val)
                else:
                    tmp.insert(0, current.val)
                if current.left:
                    stack.append(current.left)
                if current.right:
                    stack.append(current.right)
            if not tmp:
                return ans
            ans.append(tmp)
            left = not left
        return ans