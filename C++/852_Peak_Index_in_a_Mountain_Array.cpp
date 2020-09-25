class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int start = 0;
        int end = A.size();
        int mid;
        while(start < end){
            mid = (start + end) / 2;
            if(A[mid] > A[mid-1] && A[mid] > A[mid+1]) return mid;
            if(A[mid] > A[mid-1]) start = mid + 1;
            else end = mid;
        }
        return -1;
    }
};