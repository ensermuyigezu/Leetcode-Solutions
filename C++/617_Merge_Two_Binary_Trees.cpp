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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL) return t2;
        stack<vector<TreeNode*>> stack;
        stack.push({t1, t2});
        while(!stack.empty()){
            auto t = stack.top();
            stack.pop();
            if(t[0] == NULL || t[1] == NULL) continue;
            t[0]->val += t[1]->val;
            if(t[0]->left == NULL) t[0]->left = t[1]->left;
            else stack.push({t[0]->left, t[1]->left});
            if(t[0]->right == NULL) t[0]->right = t[1]->right;
            else stack.push({t[0]->right, t[1]->right});
        }
        return t1;
    }
};