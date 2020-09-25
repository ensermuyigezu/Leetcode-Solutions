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
    int i = 0;
    int cur_level = 0;
    TreeNode* recoverFromPreorder(string S) {
        if(S == "") return NULL;
        return recoverPreorder(S, 1);
    }
    TreeNode* recoverPreorder(string S, int level){
        string s;
        while(i < S.size() && S[i] != '-'){
            s += S[i];
            i++;
        }
        TreeNode* node = new TreeNode(stoi(s));
        cur_level = 0;
        while(i < S.size() && S[i] == '-'){
            i++;
            cur_level++;
        }
        if(cur_level == level && i < S.size()){
            node->left = recoverPreorder(S, level+1);   
        }
        if(cur_level == level && i < S.size()){ 
            node->right = recoverPreorder(S, level+1);;
        } 
        return node;
    }
};