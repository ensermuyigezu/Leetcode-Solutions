class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp {0};
        int k = 0;
        for(int i = 1; i <= num; i++){
            if(fmod(fmod(log2(i), 2) * 10, 10) == 0){
                k = 0;
            }
            dp.push_back(1 + dp[k]);
            k += 1;
        }
        return dp;
    }
};