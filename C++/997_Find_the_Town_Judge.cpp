class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int n = trust.size();
        if(N == 1 && n == 0) return 1;
        unordered_map<int, int> a;
        unordered_set<int> b;
        for(int i = 0; i < n; i++){
            a[trust[i][1]]++;
            if(b.count(trust[i][0]) == 0){
                b.insert(trust[i][0]);
            }
        }
        for(auto itr : a){
            if(b.count(itr.first) == 0 && itr.second == N-1){
                return itr.first;
            }
        }
        return -1;
    }
};