class Solution {
public:
    bool canJump(vector<int>& nums) {
        int x = nums.size() - 1;
        for(int i = nums.size()-2; i > -1; i--){
            if(nums[i] + i >= x)
                x = i;
        }
        return x == 0;
    }
};