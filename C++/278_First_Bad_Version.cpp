// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 0;
        int end = n;
        int ans;
        while(start < end){
            int mid = (start/2) + (end/ 2);
            if(isBadVersion(mid+1) == 1){
                ans = mid+1;
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};