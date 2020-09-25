class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int start = 0;
        int end = nums.size();
        int mid;
        while(start < end){
            mid = (start + end) / 2;
            if(mid - 1 >= start && nums[mid-1] != nums[mid] && (mid - start) % 2 == 1) end = mid;
            else if(mid - 1 >= start && nums[mid-1] == nums[mid] && (mid - start) % 2 == 0) end = mid - 1; 
            else if(mid + 1 < end && nums[mid+1] != nums[mid] && (mid - start) % 2 == 1) start = mid + 1;
            else if(mid + 1 < end && nums[mid+1] == nums[mid] && (mid - start) % 2 == 0) start = mid + 2;  
            else return nums[mid];
        }
        return -1;
    }
};