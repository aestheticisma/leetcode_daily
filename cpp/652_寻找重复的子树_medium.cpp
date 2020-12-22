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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map <string, int> treeMap;
        vector<TreeNode *> ans;
        deepTraverse(treeMap, root, ans);
        return ans;
        
    }
    string deepTraverse(unordered_map<string, int> &treeMap, TreeNode* &root, vector<TreeNode*> &ans){
        if(!root)
            return "#";
        string seq = char(root->val) + deepTraverse(treeMap,root->left,ans) + deepTraverse(treeMap,root->right,ans);
        treeMap[seq]++;
        if(treeMap[seq]==2)
            ans.push_back(root);
        return seq;
    }

};