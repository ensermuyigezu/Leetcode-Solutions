class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        d = float('-inf')
        m = float('-inf')
        for i in range(len(nums)):
            d = max(nums[i], d + nums[i])
            if d > m:
                m = d
        return m