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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector <int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        bool left = true;
        while(!nodeQueue.empty()){
            int num = nodeQueue.size();
            deque<int> tmp;
            for(int i=0; i<num; i++){
                TreeNode *current = nodeQueue.front();
                nodeQueue.pop();
                if(left)
                    tmp.push_back(current->val);
                else
                    tmp.push_front(current->val);
                if(current->left)
                    nodeQueue.push(current->left);
                if(current->right)
                    nodeQueue.push(current->right);
            }
            if(tmp.size()==0)
                return ans;
            ans.push_back(vector<int>{tmp.begin(), tmp.end()});
            left = !left;
        }
        return ans;
    }
};