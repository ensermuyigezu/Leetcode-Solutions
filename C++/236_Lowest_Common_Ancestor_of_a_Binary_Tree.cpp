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
    TreeNode* ans;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        recurse_tree(root, p, q);
        return ans;
    }
    bool recurse_tree(TreeNode* current_node, TreeNode* p, TreeNode* q){
        if(!current_node) return false;
        bool left = recurse_tree(current_node->left, p, q);
        bool right = recurse_tree(current_node->right, p, q);
        bool mid = (current_node == p || current_node == q);
        if(mid + left + right >= 2){
            ans = current_node;
        }
        return (mid || left || right);
    }
};