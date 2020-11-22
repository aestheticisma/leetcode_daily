# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# 迭代法
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        stack = []
        ans = []
        pre = None
        while root or stack:
            while root:
                stack.append(root)
                root = root.left
            root = stack.pop()
            if not root.right or root.right == pre:
                ans.append(root.val)
                pre = root
                root = None
            else:
                stack.append(root)
                root = root.right
        return ans

# 递归
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        def postOrder(root):
            # 注意递归的出口为空节点
            if not root:
                return
            postOrder(root.left)
            postOrder(root.right)
            ans.append(root.val)
        
        if not root:
            return []
        ans = []
        postOrder(root)
        return ans