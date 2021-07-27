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
    int ans = -1;
public:
    int findSecondMinimumValue(TreeNode* root) {
        int rootVal = root->val;
        dfs(root->left, rootVal);
        dfs(root->right, rootVal);
        return ans;
    }
    void dfs(TreeNode* root, int rootVal) {
        if (!root)
            return;
        if (ans != -1 && root->val >= ans)
            return;
        if (root->val > rootVal)
            ans = root->val;
        dfs(root->left, rootVal);
        dfs(root->right, rootVal);
    }
};