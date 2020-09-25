class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> a(nums.size());
        vector<int> b(nums.size());
        vector<int> c(nums.size());
        a[0] = 1;
        for(int i = 1; i < nums.size(); i++){
            a[i] = a[i-1] * nums[i-1];
        }
        b[nums.size()-1] = 1;
        for(int i = nums.size() - 2; i >= 0; i--){
            b[i] = b[i+1] * nums[i+1];
        }
        for(int i = 0; i < nums.size(); i++){
            c[i] = a[i] * b[i];
        }
        return c;
    }
};