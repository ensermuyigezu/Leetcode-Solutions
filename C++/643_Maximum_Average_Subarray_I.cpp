class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxx = INT_MIN;
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < k; i++){
            sum += nums[i];
        }
        for(int i = 0; i < n; i++){
            maxx = max(maxx, sum);
            if(i + k >= n) break;
            sum -= nums[i];
            sum += nums[i+k];
        }
        return maxx * 1.0 / k;
    }
};