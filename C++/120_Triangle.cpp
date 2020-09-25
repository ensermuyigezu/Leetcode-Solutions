class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp;
        vector<int> dp1;
        dp.push_back(triangle[0][0]);
        int m = INT_MAX;
        for (int i = 1; i < triangle.size(); i++){
            for (int j = 0; j < triangle[i].size(); j++){
                if (j != 0 && j != triangle[i].size() - 1)
                    dp1.push_back(min(dp[j-1], dp[j]) + triangle[i][j]);
                else if (j != 0)
                    dp1.push_back(dp[j-1] + triangle[i][j]);
                else
                    dp1.push_back(dp[j] + triangle[i][j]);
            }
            dp = dp1;
            dp1.clear();
        }
        return *min_element(dp.begin(), dp.end());
    }
};