class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> a;
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            a[nums[i]].push_back(i);
        }
        for(int i = 0; i < nums.size(); i++){
            if(a.count(target - nums[i]) == 1){
                if(target - nums[i] == nums[i]){
                    if(a[target-nums[i]].size() > 1){
                        ans = {a[nums[i]][0], a[nums[i]][1]};
                        break;
                    }
                } else {
                    ans = {i, a[target-nums[i]][0]};
                    break;
                }
            }
        }
        return ans;
    }
};