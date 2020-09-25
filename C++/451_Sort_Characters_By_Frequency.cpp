class Solution {
public:
    struct Comp{
        bool operator()(pair<char, int>& p1, pair<char, int>& p2){
            return p2.second >= p1.second;
        }
    };
    string frequencySort(string s) {
        string ans;
        unordered_map<char, int> mp;
        for(auto c : s){
            mp[c]++;
        }
        priority_queue<pair<char, int>, vector<pair<char, int>>, Comp> pq;
        for(auto x : mp){
            pq.push({x.first, x.second});
        }
        while(!pq.empty()){
            auto c = pq.top();
            pq.pop();
            for(int i = 0; i < c.second; i++) ans += c.first;
        }
        return ans;
    }
};