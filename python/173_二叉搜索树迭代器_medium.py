# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:

    def __init__(self, root: TreeNode):
        self.ans = []
        self.inorder(root)
        self.N = len(self.ans)
        self.idx = 0

    
    def inorder(self, root):
        if not root:
            return
        self.inorder(root.left)
        self.ans.append(root.val)
        self.inorder(root.right)
        return

    def next(self) -> int:
        res = self.ans[self.idx]
        self.idx += 1
        return res

    def hasNext(self) -> bool:
        return self.idx < self.N



# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()