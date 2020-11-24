# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

# 法一：递归

class Solution:
    def countNodes(self, root: TreeNode) -> int:
        def subcount(root):
            if not root:
                return 0
            return 1 + subcount(root.left) + subcount(root.right)
        return subcount(root)

# 法二：二分法
class Solution:
    def countNodes(self, root: TreeNode) -> int:
        def isExist(depth, mid):
            bit, node = 1<<(depth-1), root
            while(node and bit):
                if bit & mid:
                    node = node.right
                else:
                    node = node.left
                bit >>= 1
            return node != None
        if not root:
            return 0
        depth, node = 0, root
        while(node.left):
            depth += 1
            node = node.left
        low, high = 1<<depth, (1<<(depth+1)) - 1
        while(low<high):
            mid = (high-low+1)//2 + low
            if(isExist(depth, mid)):
                low = mid
            else:
                high = mid-1
        return low