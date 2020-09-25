class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        memo = [nums[0], nums[0]]
        m = memo[0]
        for i in range(1, len(nums)):
            memo = [
                max(
                    nums[i],
                    nums[i] * memo[0],
                    nums[i] * memo[1],
                ),
                min(
                    nums[i],
                    nums[i] * memo[0],
                    nums[i] * memo[1],
                ),
            ]
            if memo[0] > m:
                m = memo[0]
        return m
