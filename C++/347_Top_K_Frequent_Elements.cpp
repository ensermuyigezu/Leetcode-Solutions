class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>> pq;
        vector<int> ans;
        for(int &x : nums){
            freq[x]++;
        }
        for(auto &y : freq){
            pq.push({y.second, y.first});
        }
        for(int i = 0; i < k; i++){
            pair<int, int> top = pq.top();
            pq.pop();
            ans.push_back(top.second);
        }
        return ans;
    }
};