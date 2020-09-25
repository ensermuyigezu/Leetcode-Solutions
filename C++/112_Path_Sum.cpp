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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        bool a = false;
        bool b = false;
        if(root->left == NULL && root->right == NULL){
            return sum - root->val == 0 ? true : 0;
        } else {
            if(root->left != NULL){
                a = hasPathSum(root->left, sum-root->val);
            }
            if(a == false && root->right != NULL){
                b = hasPathSum(root->right, sum-root->val);
            }
        }
        return a || b;
    }
};