class Solution {
    class DSU {
    public:
        vector<int> parent;
        DSU(int N){
            for(int i = 0; i < N; ++i){
                parent.push_back(i);
            }
        }
        int find(int x){
            if(parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }
        void Union(int x, int y){
            parent[find(x)] = find(y);
        }
    };
public:
    int removeStones(vector<vector<int>>& stones) {
        int N = stones.size();
        DSU dsu(20000);
        for(vector<int> &stone : stones){
            dsu.Union(stone[0], stone[1] + 10000);
        }
        unordered_set<int> seen;
        for(vector<int> &stone : stones){
            seen.insert(dsu.find(stone[0]));
        }
        return N - seen.size();
    }
};