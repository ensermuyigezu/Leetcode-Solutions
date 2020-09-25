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
public:
    int i = 1;
    int n = 0;
    void traverse(vector<int> &array, TreeNode *root, int min, int max){
        if (i < n && array[i] < root->val && (array[i] >= min && array[i] <= max)){
            TreeNode *l = new TreeNode(array[i]);
            root->left = l;
            i++;
            traverse(array, l, min, root->val);
        }
        if (i < n && array[i] > root->val && (array[i] >= min && array[i] <= max)){
            TreeNode *r = new TreeNode(array[i]);
            root->right = r;
            i++;
            traverse(array, r, root->val, max);
        }
    }
    
    TreeNode *bstFromPreorder(vector<int> &preorder){
        TreeNode *root = new TreeNode(preorder[0]);
        n = preorder.size();
        traverse(preorder, root, INT_MIN, INT_MAX);
        return root;
    }
};
