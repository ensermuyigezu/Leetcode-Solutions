class Solution {
    void bfs(vector<vector<char>>& grid,  map<pair<int, int> , bool>& visited, pair<int, int> s){
        queue<pair<int, int>> q;
        q.push(s);
        vector<pair<int, int>> v {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        while(!q.empty()){
            pair<int, int> u = q.front();
            q.pop();
            for(pair<int, int> x : v){
                int nx = u.first + x.first;
                int ny = u.second + x.second;
                if(nx >= 0 && nx <= grid.size() - 1 && ny >= 0 && ny <= grid[0].size() - 1){
                    if(grid[nx][ny] == '1' && visited.count({nx, ny}) == 0){
                        visited[{nx, ny}] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        map<pair<int, int> , bool> visited;
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1' && visited.count({i, j}) == 0){
                    visited[{i, j}] = 1;
                    bfs(grid, visited, {i, j});
                    ans += 1;
                }
            }
        }
        return ans;
    }
};