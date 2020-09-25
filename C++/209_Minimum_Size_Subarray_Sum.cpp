class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;
        int len = INT_MAX;
        int begin = 0, end = 0;
        int sum = 0;
        sum += nums[0];
        while(end < nums.size()){
            if(sum > s){
                sum -= nums[begin];
                len = min(end - begin + 1, len);
                begin++;
            } else if(sum == s){
                len = min(end - begin + 1, len);
                sum -= nums[begin];
                begin++;
                end++;
                if(end < nums.size()){
                    sum += nums[end];
                }
            } else {
                if(++end < nums.size()){
                    sum += nums[end];
                }
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};