class Solution {
    class myHash {
    public:
        size_t operator()(const vector<int> & a) const {
            return a[0] + a[1];
        }
    };
    
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count = 0;
        unordered_map<vector<int>, int, myHash> m;
        for(vector<int> x : dominoes){
            sort(x.begin(), x.end());
            if(m.count(x) == 1) m[x] += 1;
            else m[x] = 1;
        }
        for(auto y : m){
            count += (y.second * (y.second-1))/2;
        }
        return count;
    }
};