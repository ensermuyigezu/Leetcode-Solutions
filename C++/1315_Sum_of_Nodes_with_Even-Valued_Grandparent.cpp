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
    int sum = 0;
    int sumEvenGrandparent(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left != NULL){
            if(root->val % 2 == 0){
                traverse(root->left, 0, 1);
            } else {
                traverse(root->left, 1, 1);
            }
        }
        if(root->right != NULL){
            if(root->val % 2 == 0){
                traverse(root->right, 0, 1);
            } else {
                traverse(root->right, 1, 1);
            }
        }
        return sum;
    }
    void traverse(TreeNode* root, bool p, bool gr){
        if(gr == 0) {
            cout << root->val << endl;
            sum += root->val;
        }
        if(root->left != NULL){
            traverse(root->left, root->val % 2, p);
        } 
        if(root->right != NULL){
            traverse(root->right, root->val % 2, p);
        }
    }
};