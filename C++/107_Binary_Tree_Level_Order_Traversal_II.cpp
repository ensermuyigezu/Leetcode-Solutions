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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL) return vector<vector<int>>();
        unordered_map<int, vector<int>> d;
        preOrderTraversal(root, 0, d);
        int n = d.size();
        vector<vector<int>> ll(n);
        int j = 0;
        for(int i = n-1; i >= 0; i--){
            ll[j] = d[i];
            j++;
        }
        return ll;
    }
    void preOrderTraversal(TreeNode* root, int i, unordered_map<int, vector<int>>& d){
        if(root != NULL){
            d[i].push_back(root->val);
            if(root->left != NULL) preOrderTraversal(root->left, i+1, d);
            if(root->right != NULL) preOrderTraversal(root->right, i+1, d);
        }
    }
};