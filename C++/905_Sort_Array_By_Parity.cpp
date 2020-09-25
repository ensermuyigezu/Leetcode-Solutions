class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        int i = 0;
        int j = 1;
        while(j < n){
            if(A[j] % 2 == 0){
                if(A[i] % 2 == 0) j++;
                else if(j > i){
                    int t = A[i];
                    A[i] = A[j];
                    A[j] = t;
                    i++;
                    j++;
                }
            } else {
                j++;
            }
            if(A[i] % 2 == 0) i++;
        }
        return A;
    }
};