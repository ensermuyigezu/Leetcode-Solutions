class Solution:
    def rob(self, nums: List[int]) -> int:
        if nums == []:
            return 0
        memo = {}
        memo[0] = nums[0]
        memo[-1] = 0
        memo[-2] = 0
        m = nums[0]
        for i in range(1, len(nums)):
            memo[i] = max(nums[i] + memo[i - 2], nums[i] + memo[i - 3])
            if memo[i] > m:
                m = memo[i]
        return m
