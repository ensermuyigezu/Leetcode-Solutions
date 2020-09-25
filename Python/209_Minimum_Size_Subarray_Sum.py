class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        i, a, r = 0, 0, float('inf')
        for j in range(len(nums)):
            a += nums[j]
            while a >= s:
                i, a, r = i+1, a-nums[i], min(r, j - i + 1)
        return 0 if r == float('inf') else r