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
    vector<int> ans;
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        right(root, 0);
        return ans;
    }
    void right(TreeNode* root, int i){
        int n = ans.size();
        if(i == n) ans.push_back(root->val);
        if(root->right != NULL) right(root->right, i+1);
        if(root->left != NULL) right(root->left, i+1);
    }
};