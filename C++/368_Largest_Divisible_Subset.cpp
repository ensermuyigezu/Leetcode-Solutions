class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() == 0){
            return nums;
        }
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> m;
        for(auto i : nums){
            m.insert({i,{i}});
        }
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                if(nums[j] % nums[i] == 0){
                    if(m[nums[j]].size() < m[nums[i]].size() + 1){
                        m[nums[j]] = m[nums[i]];
                        m[nums[j]].push_back(nums[j]);
                    }
                }
            }
        }
        vector<int> result;
        int max_size = 0;
        for(auto i : m){
            if(i.second.size() > max_size){
                max_size = i.second.size();
                result = i.second;
            }
        }
        return result;
    }
};