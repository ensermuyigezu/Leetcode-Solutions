class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int total = 0, maxsum = INT_MIN, minsum = INT_MAX, m = 0, n = 0;
        for(int a : A){
            total += a;
            m += a;
            n += a;
            maxsum = max(m, maxsum);
            m = max(m, 0);
            minsum = min(n, minsum);
            n = min(n, 0);                         
        }
        if(maxsum < 0)return maxsum;
        return max(maxsum, total-minsum);
    }
};