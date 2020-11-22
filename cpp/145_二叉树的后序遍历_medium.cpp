/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 迭代法
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<TreeNode*> stack;
        vector<int> ans;
        TreeNode *pre;
        while(root || stack.size()){
            while(root){
                stack.push_back(root);
                root = root->left;
            }
            root = stack.back();
            stack.pop_back();
            if(!root->right || root->right == pre){
                ans.push_back(root->val);
                pre = root;
                root = nullptr;
            }
            else{
                stack.push_back(root);
                root = root->right;
            }
        }
        return ans; 
    }
};

// 递归法
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postOrder(ans, root);
        return ans;
    }
    void postOrder(vector<int> &ans, TreeNode *root){
        if(!root)
            return;
        postOrder(ans, root->left);
        postOrder(ans, root->right);
        ans.push_back(root->val);
    }
};