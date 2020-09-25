class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = 0, j = 0;
        while(i < S.size()){
            if (S[i] == '#'){
                if (i == 0){
                    S.erase(i, 1);
                } else {
                    S.erase(i-1, 2);
                    i--;
                }
            } else {
                i++;
            }
        }
        while(j < T.size()){
            if (T[j] == '#'){
                if (j == 0){
                    T.erase(j, 1);
                } else {
                    T.erase(j-1, 2);
                    j--;
                }
            } else {
                j++;
            }
        }
        return (S == T);
    }
};