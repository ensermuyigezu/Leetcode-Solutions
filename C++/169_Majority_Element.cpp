class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> a;
        int n = nums.size() / 2;
        for(int x : nums){
            a[x]++;
            if(a[x] > n) return x;
        }
        return -1;
    }
};