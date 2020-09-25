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
    vector<int> inOrder;
    int minDiffInBST(TreeNode* root) {
        inOrderTraverse(root);
        int ans = INT_MAX;
        int n = inOrder.size();
        for(int i = 1; i < n; i++){
            ans = min(ans, inOrder[i] - inOrder[i-1]);
        }
        return ans;
    }
    void inOrderTraverse(TreeNode* root){
        if(root == NULL) return;
        inOrderTraverse(root->left);
        inOrder.push_back(root->val);
        inOrderTraverse(root->right);
    }
};