class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegree;
        queue<int> zero_indegree_queue;
        vector<int> order;
        for(vector<int> &x : prerequisites){
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        for(int i = 0; i < numCourses; i++){
            if(indegree.count(i) == 0){
                zero_indegree_queue.push(i);
            }
        }
        while(!zero_indegree_queue.empty()){
            int u = zero_indegree_queue.front();
            zero_indegree_queue.pop();
            order.push_back(u);
            for(int v : adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    zero_indegree_queue.push(v);
                }
            }
        }
        return order.size() == numCourses ? order : vector<int>{};
    }
};