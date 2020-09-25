class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> graph;
        for(vector<int> &x : dislikes){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vector<int> color(N, -1);
        bool is_bipartite = true;
        queue<int> q;
        for (int source = 1; source <= N; ++source) {
            if (color[source-1] == -1) {
                q.push(source);
                color[source-1] = 0;
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for (int v : graph[u]) {
                        if (color[v-1] == -1) {
                            color[v-1] = color[u-1] ^ 1;
                            q.push(v);
                        } else {
                            is_bipartite &= (color[v-1] != color[u-1]);
                            if(!is_bipartite) return false;
                        }
                    }  
                }
            }
        }   
        return is_bipartite;
    }
};