class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        bool is_bipartite = true;
        queue<int> q;
        for (int source = 0; source < n; ++source) {
            if (color[source] == -1) {
                q.push(source);
                color[source] = 0;
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for (int v : graph[u]) {
                        if (color[v] == -1) {
                            color[v] = color[u] ^ 1;
                            q.push(v);
                        } else {
                            is_bipartite &= (color[v] != color[u]);
                            if(!is_bipartite) return false;
                        }
                    }   
                }
            }
        }   
        return is_bipartite;
    }
};