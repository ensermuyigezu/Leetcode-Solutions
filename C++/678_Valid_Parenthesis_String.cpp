class Solution {
public:
    bool checkValidString(string s) {
        if(s == "") return true;
        string LEFTY = "(*", RIGHTY = ")*";
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++){
            if(s[i] == '*'){
                dp[i][i] = true;
            }
            if(i < n-1 && LEFTY.find(s[i]) != std::string::npos && RIGHTY.find(s[i+1]) != std::string::npos){
                dp[i][i+1] = true;
            }
        }
        for(int size = 2; size < n; size++){
            for(int i = 0; i < n - size; i++){
                if(s[i] == '*' && dp[i+1][i+size]){
                    dp[i][i+size] = true;
                } else if(LEFTY.find(s[i]) != std::string::npos){
                    for(int k = i+1; k < i+size+1; k++){
                        if(RIGHTY.find(s[k]) != std::string::npos && (k == i+1 || dp[i+1][k-1]) && (k == i+size || dp[k+1][i+size])){
                            dp[i][i+size] = true;
                        }
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};