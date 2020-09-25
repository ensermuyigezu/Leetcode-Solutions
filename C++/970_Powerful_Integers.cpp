class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> ans;
        unordered_set<int> set;
        int v;
        for(int i = 0; i < 30 && pow(x, i) <= bound; i++){
            for(int j = 0; j < 30 && pow(x, j) <= bound; j++){
                v = pow(x, i) + pow(y, j);
                if(v <= bound) set.insert(v);
            }
        }
        for(auto x : set){
            ans.push_back(x);
        }
        return ans;
    }
};