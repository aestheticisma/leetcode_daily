/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<int, TreeNode*> parent;
    vector<int> ans;

    void findParent(TreeNode* root) {
        if (root->left != nullptr) {
            parent[root->left->val] = root;
            findParent(root->left);
        }
        if (root->right != nullptr) {
            parent[root->right->val] = root;
            findParent(root->right);
        }
    }

    void findAns(TreeNode* root, TreeNode* from, int depth, int k) {
        if (!root)
            return;
        if (depth == k) {
            ans.emplace_back(root->val);
            return;
        }
        if (root->left != from)
            findAns(root->left, root, depth+1, k);
        if (root->right != from)
            findAns(root->right, root, depth+1, k);
        if (parent[root->val] != from)
            findAns(parent[root->val], root, depth+1, k);
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findParent(root);
        findAns(target, nullptr, 0, k);
        return ans;
    }
};