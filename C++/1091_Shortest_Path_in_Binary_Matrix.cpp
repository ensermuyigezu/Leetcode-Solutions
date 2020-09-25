class Solution {
    struct coordinate {
        int row, column;
        coordinate() : row(0), column(0) { }
        coordinate(int r, int c) : row(r), column(c) {}
        bool operator==(const coordinate& c) const {
            return row == c.row && column == c.column;
        }
    };
    class MyHashFunction { 
    public: 
        size_t operator()(const coordinate& p) const
        { 
            return p.row + p.column; 
        } 
    }; 
  
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1 || grid[grid.size()-1][grid[0].size()-1] == 1) return -1;
        if(grid.size() == 1 &&  grid[0].size() == 1) return 1;
        unordered_map<coordinate, int, MyHashFunction> d;
        grid[0][0] = 1;
        queue<coordinate> q;
        coordinate a;
        d[a] = 1;
        q.push(a);
        vector<coordinate> n = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}, {0, -1}};
        while(!q.empty()){
            coordinate u = q.front();
            q.pop();
            for(auto x : n){
                int nx = u.row + x.row;
                int ny = u.column + x.column;
                if(nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 0){
                    if (nx == grid.size()-1 && ny == grid[0].size() - 1){
                        return d[u] + 1;
                    }
                    grid[nx][ny] = 1;
                    coordinate a(nx, ny);
                    d[a] = d[u] + 1;
                    q.push(a);
                }
            }
        }
        return -1;
    }
};