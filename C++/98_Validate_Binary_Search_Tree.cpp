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
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
        return checkBST(root);
    }
    bool checkBST(TreeNode* root, long minimum = LONG_MIN, long maximum = LONG_MAX){
        if(root == NULL) return true;
        if(root->val <= minimum || root->val >= maximum){
            return false;
        }
        if(!checkBST(root->left, minimum, root->val) || !checkBST(root->right, root->val, maximum)){
            return false;
        }
        return true;
    }
};