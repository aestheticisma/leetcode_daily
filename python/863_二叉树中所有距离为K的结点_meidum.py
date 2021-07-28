# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.parent = dict()
        self.ans = list()

    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        self.parent[root.val] = None

        def findParent(root):
            if root.left:
                self.parent[root.left.val] = root
                findParent(root.left)
            if root.right:
                self.parent[root.right.val] = root
                findParent(root.right)
        
        def findAns(root, fromNode, depth, k):
            if not root:
                return
            if depth == k:
                self.ans.append(root.val)
            if root.left != fromNode:
                findAns(root.left, root, depth+1, k)
            if root.right != fromNode:
                findAns(root.right, root, depth+1, k)
            if self.parent[root.val] != fromNode:
                findAns(self.parent[root.val], root, depth+1, k)
        
        findParent(root)
        findAns(target, None, 0, k)
        return self.ans