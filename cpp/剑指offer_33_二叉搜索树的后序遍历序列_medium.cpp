// 二叉搜索树；根大于所有左子树，小于所有右子树
// 后序遍历： [ 左子树 | 右子树 | 根节点 ]
// 递归法
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return subTree(postorder, 0, postorder.size()-1);
    }
    bool subTree(vector<int>& tree, int begin, int end)
    {
        if(begin>=end) return true;
        int p = begin;
        while(tree[p]<tree[end]) p++;
        int m = p;
        while(tree[p]>tree[end]) p++;
        return p==end && subTree(tree, begin, m-1) && subTree(tree, m, end-1);
    }
};

// 辅助单调栈 
// 后序遍历数组的倒序
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        vector<int> stack;
        int root = INT_MAX;
        for(int i=postorder.size()-1; i>-1; i--)
        {
            if (postorder[i]>root) return false;
            while(!stack.empty() && postorder[i]<stack.back())
            {
                root = stack.back();
                stack.pop_back();
            }
            stack.push_back(postorder[i]);
        }
        return true;
    } 
};