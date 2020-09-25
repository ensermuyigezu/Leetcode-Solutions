class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        if(A.size() == 0) return 0;
        if(A.size() == 1) return 1;
        int begin = 0;
        int len = 1;
        char comp;
        if(A[0] < A[1]){
            comp = 'l'; 
            len = 2;
        } else if(A[0] > A[1]){
            comp = 'g';
            len = 2;
        } else {
            comp = 'r';
        }
        for(int i = 1; i < A.size() - 1; i++){
            if(A[i] < A[i+1] && (comp == 'g' || comp == 'r')){
                len = max(len, i + 1 - begin + 1);
                comp = 'l';  
                continue;
            } else if(comp == 'g'){
                if(A[i] == A[i+1]){
                    begin = i+1;
                } else {
                    begin = i;
                }
                continue;
            }
            if(A[i] > A[i+1] && (comp == 'l' || comp == 'r')){
                len = max(len, i + 1 - begin + 1);
                comp = 'g';
            } else if(comp == 'l'){
                if(A[i] == A[i+1]){
                    begin = i+1;
                } else {
                    begin = i;
                }
            }
        }   
        return len;
    }
};