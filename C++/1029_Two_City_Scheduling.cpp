class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sum = 0;
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < costs.size(); i++){
            pq.push(make_pair(costs[i][0] - costs[i][1], i));
        }
        int half = pq.size()/2;
        for(int i = 0; i < half; i++){
            sum += costs[pq.top().second][1];
            pq.pop();
        }
        for(int i = 0; i < half; i++){
            sum += costs[pq.top().second][0];
            pq.pop();
        }
        return sum;
    }
};