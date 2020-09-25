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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode* node = new TreeNode();
            node->val = val;
            return node;
        }
        if(val < root->val){
            if(root->left == NULL){
                TreeNode* node = new TreeNode();
                node->val = val;
                root->left = node;
                return root;
            } else {
                insertIntoBST(root->left, val);   
            }
        } else {
            if(root->right == NULL){
                TreeNode* node = new TreeNode();
                node->val = val;
                root->right = node;
                return root;
            } else {
                insertIntoBST(root->right, val);   
            }
        }
        return root;
    }
};