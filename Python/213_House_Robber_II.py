class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return 0
        if n == 1:
            return nums[0]
        if n == 2:
            return max(nums[0], nums[1])
        memo = {}
        dp = {}
        memo[0] = nums[0]
        memo[1] = memo[0]
        memo[2] = memo[0] + nums[2]
        for i in range(3, len(nums)):
            memo[i] = max(memo[i - 1], memo[i - 2] + nums[i])
        dp = {}
        dp[0] = 0
        dp[1] = nums[1]
        for i in range(2, len(nums)):
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
        return max(memo[n - 2], dp[n - 1])
