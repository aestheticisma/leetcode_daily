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
class BSTIterator {
private:
    vector<int> ans;
    int idx;
    void inorder(TreeNode *root, vector<int> &ans) {
        if (!root) return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
        return;
    }
    vector<int> inorderTravelsal(TreeNode *root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
public:
    BSTIterator(TreeNode* root): idx(0), ans(inorderTravelsal(root)) {}
    
    int next() {
        return ans[idx++];
    }
    
    bool hasNext() {
        return idx < ans.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */