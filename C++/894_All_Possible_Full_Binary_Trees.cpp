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
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N % 2 == 0) return {};
        vector<vector<TreeNode*>> dp(N+1);
        dp[1] = {new TreeNode(0)};
        for(int sub = 3; sub <= N; sub+=2){ 
            for(int left = 1; left < sub; left += 2){ 
                int right = sub - 1 - left; 
                for(auto& l : dp[left]){
                    for(auto& r : dp[right]){
                        TreeNode* root = new TreeNode(0);
                        root->left = l;
                        root->right = r;
                        dp[sub].push_back(root);
                    }
                }
            }
        }
        return dp[N];
    }
};