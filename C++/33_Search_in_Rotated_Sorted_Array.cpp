class Solution {
public:
    int Search(vector<int>& l, int left, int right, int k){
        int mid = (left + right)/2;
        if(k == l[mid]){
            return mid;
        }
        if(right < left){
            return -1;
        }
        if(l[left] < l[mid]){
            if(k >= l[left] && k < l[mid]){
                return Search(l, left, mid - 1, k);
            } else {
                return Search(l, mid+1, right, k);
            }
        } else if (l[mid] < l[left]){
            if(k >= l[mid] && k <= l[right]){
                return Search(l, mid+1, right, k);
            } else {
                return Search(l, left, mid - 1, k);
            }
        } else if(l[left] == l[mid]){
            if(l[mid] != l[right]){
                return Search(l, mid+1, right, k);
            } else {
                int result = Search(l, left, mid-1, k);
                if(result == -1){
                    return Search(l, mid+1, right, k);
                } else {
                    return result;
                }
            }
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int le = 0;
        int r = nums.size() - 1;
        if(nums.empty()) return -1;
        return Search(nums, le, r, target);
    }
};