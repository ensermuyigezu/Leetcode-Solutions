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
    int maxSum = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        maxPathSum1(root);
        return maxSum;
    }
    int maxPathSum1(TreeNode* root){
        int l = -INT_MAX, r = -INT_MAX;
        int m = 0;
        if(root->left == NULL && root->right == NULL){
            m = root->val;
            maxSum = max(maxSum, m);
        } else {
            if(root->left != NULL){
                l = maxPathSum1(root->left);   
            }
            if(root->right != NULL){
                r = maxPathSum1(root->right);   
            }
            if(l > 0 && r > 0){
                maxSum = max(maxSum, root->val + l + r);
            }
            if(l > r){
                m = max(l + root->val, root->val);
            } else {
                m = max(r + root->val, root->val);
            }
            maxSum = max(maxSum, m);
        }
        return m;
    }
};