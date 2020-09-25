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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        vector<int> a = diameter(root);
        return a[0] >= a[1] ? a[0] : a[1];
    }
    vector<int> diameter(TreeNode* root){
        if(root == NULL){
            return {0, 0};
        }
        if(root->left == NULL && root->right == NULL){
            return {0, 0};
        } else {
            vector<int> a {0, 0};
            vector<int> b {0, 0};
            if(root->left != NULL){
                a = diameter(root->left);
            }
            if(root->right != NULL){
                b = diameter(root->right);
            }
            if(root->left != NULL && root->right != NULL){
                return {max({a[0], b[0], a[1] + b[1] + 2}), max({a[1], b[1]}) + 1};
            }
            return {max({a[0], b[0], a[1] + b[1] + 1}), max({a[1], b[1]}) + 1};
        }
    }
};