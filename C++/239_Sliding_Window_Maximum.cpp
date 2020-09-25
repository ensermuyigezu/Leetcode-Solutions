class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> a;
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < k; i++){
            a.insert(nums[i]);
        }
        ans.push_back(*(--a.end()));
        for(int i = 0; i < n - k; i++){
            a.erase(a.find(nums[i]));
            a.insert(nums[i+k]);
            ans.push_back(*(--a.end()));
        }
        return ans;
    }
};