class Solution {
public:
    vector<vector<int>> memo;
    int n;
    int m;
    int ans = 0;
    int dfs(vector<vector<int>>& matrix, int r, int c){
        if(memo[r][c] != 0) return memo[r][c];
        int len = 1;
        if(c-1 >= 0 && matrix[r][c] > matrix[r][c-1]) 
            len = max(len, 1 + dfs(matrix, r, c-1));
        if(c+1 < m && matrix[r][c] > matrix[r][c+1]) 
            len = max(len, 1 + dfs(matrix, r, c+1));
        if(r-1 >= 0 && matrix[r][c] > matrix[r-1][c]) 
            len = max(len, 1 + dfs(matrix, r-1, c));
        if(r+1 < n && matrix[r][c] > matrix[r+1][c]) 
            len = max(len, 1 + dfs(matrix, r+1, c));
        memo[r][c] = len;
        ans = max(ans, len);
        return len;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;      
        n = matrix.size();
        m = matrix[0].size();
        memo.resize(n, vector<int>(m, 0));
        for(int r = 0; r < n; r++)
            for(int c = 0; c < m; c++)
                if(memo[r][c] == 0)
                    dfs(matrix, r, c);
        return ans;
    }
};