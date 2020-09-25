class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) return false;
        unordered_map<int, int> a;
        for(int i = 0; i <= k; i++){
            if(i >= n) break;
            a[nums[i]]++;
            if(a[nums[i]] > 1) return true;
        }
        for(int i = 1; i < n; i++){
            a[nums[i-1]]--;
            if(i+k < n) a[nums[i+k]]++;   
            if(a[nums[i]] >= 2) return true;
        }
        return false;
    }
};