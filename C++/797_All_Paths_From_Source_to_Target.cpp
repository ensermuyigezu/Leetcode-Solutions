class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> a {0};
        dfs(0, graph.size()-1, graph, a);
        return ans;
    }
    void dfs(int s, int t, vector<vector<int>>& graph, vector<int> p){
        for(int i : graph[s]){
            if(i == t){
                p.push_back(i);
                ans.push_back(p);
                p.pop_back();
            } else {
                p.push_back(i);
                dfs(i, t, graph, p);
                p.pop_back();
            }
            
        }
    }
};