class Solution {
public:
    int ans = INT_MAX;
    int dst;
    int k;
    unordered_map<int, vector<pair<int, int>>> graph;
    unordered_set<int> visited;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        this->k = K;
        this->dst = dst;
        for(auto &x : flights){
            graph[x[0]].push_back(make_pair(x[1], x[2]));
        }
        visited.insert(src);
        dfs(src, -1, 0);
        return ans == INT_MAX ? -1 : ans;
    }
    void dfs(int src, int K, int cost){
        if(src == dst){
            if(K <= k && cost <= ans){
                ans = cost;
            }
            return;
        } else if(K > k || cost >= ans){
            return;
        }
        for(pair<int, int> &x : graph[src]) {
            if(visited.count(x.first) == 0) {
                visited.insert(x.first);
                dfs(x.first, K + 1, cost + x.second);
                visited.erase(x.first);
            }
        }
    }
};