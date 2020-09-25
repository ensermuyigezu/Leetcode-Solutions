class Solution {
    typedef pair<int,pair<int,int>> ppi;
    class comp {
	public:
	    bool operator()(ppi a, ppi b){
		    return a.first > b.first;
        }
	};
public:
	int swimInWater(vector<vector<int>>& grid) {
		int ans = INT_MIN;
		vector<int> dir{1, 0, -1, -0, 1};
		priority_queue<ppi, vector<ppi>, comp> pq;
		int m = grid.size();
		int n = grid[0].size();
        
	    vector<vector<int>> visited(m, vector<int>(n));
		visited[0][0] = 1;

		pq.push({grid[0][0], {0,0}});
		while(!pq.empty()){
			ans = max(ans, pq.top().first);
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			pq.pop();
			if(x == m-1 && y == n-1) break;
			for(int i = 0; i < 4; i++) {
				int a = x + dir[i];
				int b = y + dir[i+1];
				if(a >= 0 && a < m && b >= 0 && b < n && !visited[a][b]) {
					visited[a][b] = 1;
					pq.push({grid[a][b], {a,b}});
				}
			}
		}
		return ans;
	}
};