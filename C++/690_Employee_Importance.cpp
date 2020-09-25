/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int, Employee*> mp;
    int getImportance(vector<Employee*> employees, int id) {
        for(auto &x : employees){
            mp[x->id] = x;
        }
        return dfs(id);
    }
    int dfs(int id){
        auto employee = mp[id];
        int ans = employee->importance;
        for(int subid : employee->subordinates){
            ans += dfs(subid);
        }
        return ans;
    }
};