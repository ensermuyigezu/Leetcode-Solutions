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
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int, TreeNode*> a = find(root, NULL, x, 0);
        pair<int, TreeNode*> b = find(root, NULL, y, 0);
        if(a.first == b.first && a.second != b.second) return true;
        return false;
    }
    pair<int, TreeNode*> find(TreeNode* root, TreeNode* parent, int x, int i){
        if(root->val == x) return {i, parent};
        pair<int, TreeNode*> a;
        pair<int, TreeNode*> b;
        if(root->left != NULL) a = find(root->left, root, x, i+1);
        if(a.second != NULL) return a;
        if(root->right != NULL) b = find(root->right, root, x, i+1);
        if(b.second != NULL) return b;
        return {0, NULL};
    }
};