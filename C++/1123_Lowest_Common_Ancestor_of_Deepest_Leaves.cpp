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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root)
            return NULL;
        int l = countDepth(root->left);
        int r = countDepth(root->right);
        if(l == r)
            return root;
        else if(l < r)
            return lcaDeepestLeaves(root->right);
        else
            return lcaDeepestLeaves(root->left);
    }
    
    int countDepth(TreeNode* root){
        if(!root)
            return 0;
        return 1 + max(countDepth(root->left), countDepth(root->right));
    } 
};