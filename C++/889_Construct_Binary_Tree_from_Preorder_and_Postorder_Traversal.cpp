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
    vector<int> pre;
    vector<int> post;
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        this->pre = pre;
        this->post = post;
        return make(0, 0, pre.size());
    }
    TreeNode* make(int i0, int i1, int N){
        if(N == 0) return NULL;
        TreeNode* root = new TreeNode(pre[i0]);
        if(N == 1) return root;
        int L = 1;
        for(; L < N; ++L){
            if(post[i1 + L-1] == pre[i0 + 1]) break;
        }
        root->left = make(i0+1, i1, L);
        root->right = make(i0+L+1, i1+L, N-1-L);
        return root;
    }
};