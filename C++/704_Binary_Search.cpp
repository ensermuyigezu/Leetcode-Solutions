class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size();
        int mid;
        while(start < end){
            mid = (start + end) / 2 ;
            if(target == nums[mid]) return mid;
            else if(target < nums[mid]) end = mid;
            else start = mid + 1;
        }
        return -1;
    }
};