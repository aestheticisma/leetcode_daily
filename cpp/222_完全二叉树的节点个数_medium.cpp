
 // Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 法一：递归
class Solution {
public:
    int countNodes(TreeNode* root) {
        return subcount(root);
    }
    int subcount(TreeNode* root){
        if(root==nullptr)
            return 0;
        return 1+subcount(root->left)+subcount(root->right);
    }
};