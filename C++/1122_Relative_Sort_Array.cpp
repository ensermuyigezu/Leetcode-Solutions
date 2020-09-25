class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        set<int> a;
        vector<int> ans;
        unordered_map<int, int> m;
        for(int x : arr1){
            a.insert(x);
            m[x] += 1;
        }
        for(int x : arr2){
            for(int i = 0; i < m[x]; i++){
                ans.push_back(x);
            }
            a.erase(x);
        }
        for(auto i = a.begin(); i != a.end(); i++){
            for(int j = 0; j < m[*i]; j++){
                ans.push_back(*i);
            }
        }
        return ans;   
    }
};