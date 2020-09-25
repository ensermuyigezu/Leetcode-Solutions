class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int prev = 0;
        int sum = -INT_MAX;
        for (int x : nums){
            prev = max(prev + x, x);
            if (prev > sum)
                sum = prev;
        }
        return sum;
    }
};