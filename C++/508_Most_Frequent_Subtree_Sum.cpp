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
    unordered_map<int, int> mp;
    int max = 0;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(root == NULL) return vector<int> {};
        vector<int> ans;
        Sum(root, 0);
        for(auto &x : mp){
            if(x.second == max) ans.push_back(x.first);
        }
        return ans;
    }
    int Sum(TreeNode* root, int sum){
        int a = 0;
        int b = 0;
        if(root == NULL) 0;
        if(root->left != NULL) a = Sum(root->left, sum);
        if(root->right != NULL) b = Sum(root->right, sum);
        mp[a+b+root->val]++;
        if(mp[a+b+root->val] > max) max = mp[a+b+root->val];
        return a + b + root->val;
    }
};