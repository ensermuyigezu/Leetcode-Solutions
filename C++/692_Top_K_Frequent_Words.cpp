class Solution {
public:
    struct Compare {
        bool operator()(pair<int, string>& p1, pair<int, string>& p2){
            return p2.first > p1.first || (p1.first == p2.first && p2.second < p1.second);
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;
        unordered_map<string, int> mp;
        for(int i = 0; i < words.size(); i++){
            mp[words[i]]++;
        }
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            pq.push(make_pair(itr->second, itr->first));
        }
        while(k != 0){
            auto u = pq.top();
            pq.pop();
            ans.push_back(u.second);
            k--;
        }
        return ans;
    }
};