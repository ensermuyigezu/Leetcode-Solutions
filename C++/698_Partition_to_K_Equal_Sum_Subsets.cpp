class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        int target = sum / k;
        int rem = sum % k;
        if(rem) return false;
        sort(nums.begin(), nums.end());
        if(nums[n-1] > target) return false;
        while(!nums.empty() && nums.back() == target){
            nums.pop_back();
            k--;
        }
        vector<int> a(k, 0);
        return search(nums, a, target);
    }
    bool search(vector<int>& nums, vector<int>& groups, int target){
        if(nums.empty()) return true;
        int v = nums.back();
        nums.pop_back();
        for(int i = 0; i < groups.size(); i++){
            if(groups[i] + v <= target){
                groups[i] += v;
                if(search(nums, groups, target)) return true;
                groups[i] -= v;
            }
            if(groups[i] == 0) break;
        }
        nums.push_back(v);
        return false;
    }
};