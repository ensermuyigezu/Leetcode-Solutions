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
    int ans = 0;
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL) return ans;
        traverse(root);
        return ans-1;
    }
    int traverse(TreeNode* root){
        if(root == NULL) return 0;
        int a = 0;
        int b = 0;
        if(root->left != NULL){
            if(root->val == root->left->val){
                a = traverse(root->left);
            } else {
                traverse(root->left);
            }
        }
        if(root->right != NULL){
            if(root->val == root->right->val){
                b = traverse(root->right);
            } else {
                traverse(root->right);
            }
        }
        ans = max(ans, a + b + 1);
        return (a && b) ? max(a, b) + 1 : a + b + 1;
    }
};