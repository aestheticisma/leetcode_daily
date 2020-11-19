# 二叉搜索树；根大于所有左子树，小于所有右子树
# 后序遍历： [ 左子树 | 右子树 | 根节点 ]
# 递归法
class Solution(object):
    def verifyPostorder(self, postorder):
        """
        :type postorder: List[int]
        :rtype: bool
        """
        def subtree(begin, end):
            if begin >= end:
                return True
            p = begin
            while postorder[p] < postorder[end]: p += 1
            m = p
            while postorder[p] > postorder[end]: p += 1
            return p==end and subtree(begin, m-1) and subtree(m, end-1)
        return subtree(0, len(postorder)-1)

# 辅助单调栈
class Solution(object):
    def verifyPostorder(self, postorder):
        """
        :type postorder: List[int]
        :rtype: bool
        """
        stack, root = [], float('+inf')
        for i in range(len(postorder)-1, -1, -1):
            if postorder[i] > root: return False
            while stack and postorder[i] < stack[-1]:
                root = stack.pop()
            stack.append(postorder[i])
        return True