class Solution {
    struct coordinate {
        int x0, y0, x1, y1, distance;
        coordinate(int x0, int y0, int x1, int y1) : x0(x0), y0(y0), x1(x1), y1(y1){}
        bool operator==(const coordinate& c) const {
            return x0 == c.x0 && y0 == c.y0 && x1 == c.x1 && y1 == c.y1;
        }    
    };
    
    class myHash {
    public:
        size_t operator()(const coordinate& c) const {
            return c.x0 + c.y0 + c.x1 + c.y1;
        }
    };
    
    void right(vector<vector<int>>& grid, vector<coordinate>& v, coordinate& u){
        if(u.x0 == u.x1 && u.y1+1 < grid[0].size() && grid[u.x1][u.y1+1] == 0){
                coordinate a(u.x0, u.y0+1, u.x1, u.y1+1);
                v.push_back(a);
        } else if(u.y0 == u.y1 && u.y1+1 < grid[0].size() && grid[u.x0][u.y0+1] == 0 && grid[u.x1][u.y1+1] == 0){
                coordinate a(u.x0, u.y0 + 1, u.x1, u.y1+1);
                v.push_back(a);
        }
    }
    
    void down(vector<vector<int>>& grid, vector<coordinate>& v, coordinate& u){
        if(u.y0 == u.y1 && u.x1+1 < grid.size() && grid[u.x1+1][u.y1] == 0){
                coordinate a(u.x0 + 1, u.y0, u.x1 + 1, u.y1);
                v.push_back(a);
        } else if(u.x0 == u.x1 && u.x0 + 1 < grid.size() && grid[u.x0+1][u.y0] == 0 && grid[u.x1+1][u.y1] == 0){
                coordinate a(u.x0 + 1, u.y0, u.x1 + 1, u.y1);
                v.push_back(a);
        }
    }
    
    void clockwise(vector<vector<int>>& grid, vector<coordinate>& v, coordinate& u){
        if(u.x0 == u.x1 && u.x0 + 1 < grid.size() && grid[u.x0+1][u.y0] == 0 && grid[u.x0+1][u.y1] == 0){
            coordinate a(u.x0, u.y0, u.x0 + 1, u.y0);
            v.push_back(a);
        }
    }
        
    void counterclockwise(vector<vector<int>>& grid, vector<coordinate>& v, coordinate& u){
        if(u.y0 == u.y1 && u.y0+1 < grid[0].size() && grid[u.x0][u.y0+1] == 0 && grid[u.x1][u.y1+1] == 0){
            coordinate a(u.x0, u.y0, u.x0, u.y0 + 1);
            v.push_back(a);
        }
    }
        
public:
    int minimumMoves(vector<vector<int>>& grid) {
        unordered_set<coordinate, myHash> d;
        queue<coordinate> q;
        int r = grid.size();
        int c = grid[0].size();
        coordinate ans(r-1, c-2, r-1, c-1);
        coordinate a(0, 0, 0, 1);
        a.distance = 0;
        q.push(a);
        while(!q.empty()){
            coordinate u = q.front();
            q.pop();
            vector<coordinate> v;
            right(grid, v, u);
            down(grid, v, u);
            clockwise(grid, v, u);
            counterclockwise(grid, v, u);
            for(auto x : v){
                if(d.count(x) == 0){
                    if(ans == x) return u.distance + 1;
                    x.distance = u.distance + 1;
                    d.insert(x);
                    q.push(x);
                }
            }
        }
        return -1;
    }
};