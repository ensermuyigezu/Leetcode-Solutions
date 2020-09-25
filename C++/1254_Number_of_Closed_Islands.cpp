class Solution {
    struct hash_pair {
        template < class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);
            return hash1 ^ hash2;
        }
    };
    
    bool dfs(vector<vector<int>>& grid, unordered_set<pair<int, int>, hash_pair>& visited, pair<int, int> u){
        pair<int, int> arr[4] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        int x = 1;
        for(auto v : arr){
            int nx = u.first + v.first;
            int ny = u.second + v.second;
            if(nx < 0 || nx == grid.size() || ny < 0 || ny == grid[0].size()){
                x = 0;
            } else if(grid[nx][ny] == 0 && visited.count({nx, ny}) == 0){
                visited.insert({nx, ny});
                bool a = dfs(grid, visited, {nx, ny});
                if(!a) x = 0;
            }
        }
        return x;
    }
    
public:
    int closedIsland(vector<vector<int>>& grid) {
        int num = 0;
        unordered_set<pair<int, int>, hash_pair> visited;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0 && visited.count({i, j}) == 0){
                    visited.insert({i, j});
                    if(dfs(grid, visited, {i, j})){
                        num += 1;
                    }
                }
            }
        }
        return num;
    }
};