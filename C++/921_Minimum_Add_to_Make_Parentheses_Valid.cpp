class Solution {
public:
    int minAddToMakeValid(string S) {
        int ans = 0;
        int bal = 0;
        for(int i = 0; i < S.size(); i++){
            if(S[i] == '(') bal++;
            else bal--;
            if(bal == -1){
                ans++;
                bal++;
            }
        }
        return ans + bal;
    }
};