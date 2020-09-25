class Solution {
public:
    vector<int> dr {-1, 0, 1, 0};
    vector<int> dc {0, -1, 0, 1};
    vector<vector<int>> grid;
    int N;
    int largestIsland(vector<vector<int>>& grid) {
        this->N = grid.size();
        int index = 2;
        vector<int> area(N*N + 2);
        for(int r = 0; r < N; ++r){
            for(int c = 0; c < N; ++c){
                if(grid[r][c] == 1){
                    area[index] = dfs(grid, r, c, index);
                    index++;
                }
            }
        }
        int ans = 0;
        for(int x : area) ans = max(ans, x);
        for(int r = 0; r < N; ++r){
            for(int c = 0; c < N; ++c){
                if(grid[r][c] == 0){
                    unordered_set<int> seen;
                    for(int move : neighbors(r, c)){
                        if(grid[move / N][move % N] > 1){
                            seen.insert(grid[move / N][move % N]);
                        }
                    }
                    int bns = 1;
                    for(int i : seen) bns += area[i];
                    ans = max(ans, bns);
                }
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>>& grid, int r, int c, int index){
        int ans = 1;
        grid[r][c] = index;
        for(int move : neighbors(r, c)){
            if(grid[move / N][move % N] == 1){
                grid[move / N][move % N] = index;
                ans += dfs(grid, move / N, move % N, index);
            }
        }
        return ans;
    }
    vector<int> neighbors(int r, int c){
        vector<int> ans;
        for(int k = 0; k < 4; ++k){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(nr >= 0 && nr < N && nc >= 0 && nc < N){
                ans.push_back(nr * N + nc);
            }
        }
        return ans;
    }
};