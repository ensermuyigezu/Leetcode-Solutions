class Solution {
public:
    unordered_set<int> parent;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        for(int i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i = 0; i < numCourses; i++){
            if(parent.count(i) == 0){
                parent.insert(i);
                if(dfs(i, graph)) return false;
                parent.erase(i);
            }
        }
        return true;
    }
    bool dfs(int s, unordered_map<int, vector<int>>& graph){
        for(int x : graph[s]){
            if(parent.count(x) == 1){
                return true;
            } else {
                parent.insert(x);
                if(dfs(x, graph)) return true;
                parent.erase(x);
            }
        }
        return false;
    }
};