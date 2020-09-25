class Solution:
    def countBits(self, num: int) -> List[int]:
        dp = [0]
        k = 0
        for i in range(1, num+1):
            if ((math.log2(i)%2)*10)%10 == 0:
                k = 0
            dp.append(1 + dp[k])
            k += 1
        return dp