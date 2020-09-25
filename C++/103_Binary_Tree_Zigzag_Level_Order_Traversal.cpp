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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return vector<vector<int>>();
        unordered_map<int, vector<int>> d;
        preOrderTraversal(root, 0, d);
        int n = d.size();
        vector<vector<int>> ll(n);
        for(int i = 0; i < n; i++){
            ll[i] = d[i];
        }
        bool a = 0;
        for(auto &x : ll){
            if(a){
                reverse(x.begin(), x.end());
            }
            a = !a;
            cout << a << endl;
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