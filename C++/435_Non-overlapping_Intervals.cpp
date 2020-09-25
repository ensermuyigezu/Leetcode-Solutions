class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
        int k = 1;
        sort(intervals.begin(), intervals.end(), [&](const vector<int>& a, const vector<int>& b){
            return a[1] <= b[1]; 
        });
        int end = intervals[0][1];
        for(auto &x : intervals){
            if(x[0] >= end){
                end = x[1];
                k += 1;
            }
        }
        return intervals.size() - k;
    }
};