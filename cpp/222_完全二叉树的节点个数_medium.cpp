
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

// 法二：结合完全二叉树自身的特点，已知，完全二叉树的最深层一定在左边，因此先通过最左边的叶子结点判断出树的深度，同时,\
	最后一层的数量1<=m<=(2^n) （设深度为n, 根一层深度为0），因此树的总节点数( 2^n<=x<=(2^(n+1))-1 )\
	之后通过二分法判断该序号的节点存在与否。
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int depth = 0;
        TreeNode *node = root;
        while(node->left!=nullptr){
            depth++;
            node = node->left;
        }
        // if(!depth)
        //     return 1;
        // int low = 1<<depth, high = (1<<(depth+1)) - 1;
        // while(low<=high){
        //     int mid = (low+high)/2;
        //     if(isExist(root, depth, mid))
        //         low = mid+1;
        //     else
        //         high = mid-1;
        // }
        int low = 1<<depth, high = (1<<(depth+1)) - 1;
        while(low<high){
        	int mid = (high-low+1)/2 + low;
        	if(isExist(rootm depth, mid))
        		low = mid;
        	else
        		high = mid-1;
        }
        return low;
    }
    bool isExist(TreeNode *root, int depth, int mid){
        TreeNode *node = root;
        int bit = 1<<(depth-1);
        while(node != nullptr && bit){
            if(bit & mid)
                node = node->right;
            else
                node = node->left;
            bit>>=1;
        }
        return node!=nullptr;
    }
};