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
    vector<int> ans;
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        inorder(root, low, high);
        return accumulate(ans.begin(), ans.end(), 0);
    }
    void inorder(TreeNode* root, int& low, int& high) {
        if (root == nullptr) return;
        inorder(root->left, low, high);
        if (root->val>=low && root->val<=high)
            ans.push_back(root->val);
        inorder(root->right, low, high);
    }
};