class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> a;
        unordered_set<int> b;
        for(int i = 0; i < arr.size(); i++){
            a[arr[i]] += 1;
        }
        for(auto x : a){
            if(b.count(x.second) == 1) return false;
            b.insert(x.second);
        }
        return true;
    }
};