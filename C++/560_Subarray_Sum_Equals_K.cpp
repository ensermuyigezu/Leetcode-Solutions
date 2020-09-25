class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int begin = 0, end = 0;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            sum = 0;
            begin = i;
            end = i;
            while(end < nums.size()){
                sum += nums[end];
                if(sum == k) {
                    ans++;
                }
                end++;
            }
        }
        return ans;
    }
};