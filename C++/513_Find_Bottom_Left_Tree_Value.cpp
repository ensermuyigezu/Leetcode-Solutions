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
    int max = -1;
    int ans;
    int findBottomLeftValue(TreeNode* root) {
        Traverse(root, 0);
        return ans;
    }
    void Traverse(TreeNode* root, int d){
        if(root == NULL) return;
        if(root->left != NULL) Traverse(root->left, d+1);
        if(root->right != NULL) Traverse(root->right, d+1);
        if(d > max){
            max = d;
            ans = root->val;
        }
    }
};