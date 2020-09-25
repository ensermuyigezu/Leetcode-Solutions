class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size(), 0));
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(j - 1 >= 0 && i - 1 >= 0){
                    dp[i][j] = min(grid[i][j] + dp[i][j-1], grid[i][j] + dp[i-1][j]);
                } else if(j - 1 >= 0){
                    dp[i][j] = grid[i][j] + dp[i][j-1];
                } else if(i - 1 >= 0) {
                    dp[i][j] = grid[i][j] + dp[i-1][j];
                } else {
                    dp[i][j] = grid[i][j];
                }
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};