class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1, hi = 1000000;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int sum = 0;
            for (int num : nums) {
                sum += num / mid + (num % mid == 0 ? 0 : 1); 
            }
            if (sum <= threshold) hi = mid - 1;
            else lo = mid + 1;
        }
        return lo;
    }
};