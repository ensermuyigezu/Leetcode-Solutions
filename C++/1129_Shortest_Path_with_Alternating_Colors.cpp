class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        unordered_map<int, vector<int>> d;
        unordered_map<int, vector<bool>> visited;
        for(int i = 0; i < n; i++){
            visited[i] = {false, false};
            d[i] = {INT_MAX, INT_MAX};
        }
        visited[0] = {true, true};
        d[0] = {0, 0};
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(visited[u][1] == true){
                for(vector<int> x : red_edges){
                    if(u == x[0] && (visited[x[1]][0] == false || d[u][1] + 1 <                           d[x[1]][0])){
                        d[x[1]][0] = d[u][1] + 1;
                        visited[x[1]][0] = true;
                        q.push(x[1]);
                    }
                }
            }
            if(visited[u][0] == true){
                for(vector<int> y : blue_edges){
                    if(u == y[0] && (visited[y[1]][1] == false || d[u][0] + 1 <                           d[y[1]][1])){
                        d[y[1]][1] = d[u][0] + 1;
                        visited[y[1]][1] = true;
                        q.push(y[1]);
                    }
                }
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            int x = *min_element(d[i].begin(), d[i].end());
            if(x == INT_MAX){
                ans.push_back(-1);
            } else {
                ans.push_back(x);
            }
        }
        return ans;
    }
};