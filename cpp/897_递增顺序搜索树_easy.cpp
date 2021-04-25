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
class Solution {
private:
    TreeNode *cur;
public:
    void inorder(TreeNode* node) {
        if (node==nullptr) return;
        inorder(node->left);
        cur->right = node;
        node->left = nullptr;
        cur = node;
        inorder(node->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummyHead = new TreeNode();
        cur = dummyHead;
        inorder(root);
        return dummyHead->right;
    }
};