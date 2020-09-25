class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        dp = []
        dp1 = []
        dp.append(triangle[0][0])
        m = float('inf')
        for i in range(1, len(triangle)):
            for j in range(len(triangle[i])):
                if j != 0 and j != len(triangle[i]) - 1:
                    dp1.append(min(dp[j-1], dp[j]) + triangle[i][j])
                elif j != 0:
                    dp1.append(dp[j-1] + triangle[i][j])
                else:
                    dp1.append(dp[j] + triangle[i][j])
            dp = dp1
            dp1 = []
        return min(dp)