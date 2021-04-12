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
public:
    int minDiffInBST(TreeNode* root) {
        int pre = -1;
        int ans = INT_MAX;
        dfs(root, pre, ans);
        return ans;
    }
    
    void dfs(TreeNode *root, int &pre, int &ans) {
        if (!root) return;
        dfs(root->left, pre, ans);
        if (pre != -1) ans = min(ans, root->val - pre);
        cout<<ans<<endl;
        pre = root->val;
        dfs(root->right, pre, ans);
    }
};