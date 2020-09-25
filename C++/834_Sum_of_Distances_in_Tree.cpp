class Solution {
public:
    vector<int> ans;
    vector<int> count;
    vector<unordered_set<int>> graph;
    int N;
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        this->N = N;
        ans = vector<int> (N, 0);
        count = vector<int> (N, 1);
        for(int i = 0; i < N; ++i){
            graph.push_back(unordered_set<int>{});
        }
        for(vector<int> &edge : edges){
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return ans;
    }
    void dfs(int node, int parent){
        for(int child : graph[node]){
            if(child != parent){
                dfs(child, node);
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
        }
    }
    void dfs2(int node, int parent){
        for(int child : graph[node]){
            if(child != parent){
                ans[child] = ans[node] - count[child] + N - count[child];
                dfs2(child, node);
            }
        }
    }
};