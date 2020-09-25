class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int freshOranges = 0;
        vector<pair<int, int>> rottenLocations;
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    freshOranges++;
                if (grid[i][j] == 2)
                    rottenLocations.push_back(make_pair(i, j));
            }
        }
        int maxTime = 0;
        queue<pair<pair<int, int>, int>> bfsQueue;
        for (auto rc: rottenLocations) {
            int r = rc.first;
            int c = rc.second;
            bfsQueue.push(make_pair(make_pair(r, c), 0));
        }
        auto isInBounds = [&](const int r, const int c) {
            return (r >= 0 && r < n && c >= 0 && c < m);
        };
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!bfsQueue.empty()) {
            auto curr = bfsQueue.front();
            bfsQueue.pop();
            int currR = curr.first.first;
            int currC = curr.first.second;
            int currTime = curr.second;
            for(auto direction: directions) {
                int r = currR + direction[0];
                int c = currC + direction[1];
                if(isInBounds(r, c) && grid[r][c] == 1) {
                    freshOranges--;
                    grid[r][c] = 2;
                    bfsQueue.push(make_pair(make_pair(r, c), currTime + 1));
                    maxTime = max(maxTime, currTime + 1);
                }
            }
        }
        return (freshOranges ? -1 : maxTime);
    }
};