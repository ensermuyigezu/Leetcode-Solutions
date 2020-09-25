class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        unordered_map<string, int> freq;
        unordered_map<int, int> d;
        vector<pair<string, int>> a;
        vector<string> ans;
        queue<int> q;
        q.push(id);
        d[id] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int x : friends[u]){
                if(d.count(x) == 0){
                    d[x] = d[u] + 1;
                    q.push(x);
                    if(d[x] == level){
                        for(string i : watchedVideos[x]){
                            freq[i]++;
                        }
                    }
                }
            }
        }
        for(auto itr = freq.begin(); itr != freq.end(); itr++){
            a.push_back({itr->first, itr->second});
        }
        sort(a.begin(), a.end(), [](const pair<string, int>& x, const pair<string, int>& y){         
            if(x.second == y.second) return x.first < y.first;
            return (x.second < y.second);
        });
        for(auto x : a){
            ans.push_back(x.first);
        }
        return ans;
    }
};