class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        if nums == []:
            return 0
        memo = {}
        for i in range(0, len(nums)):
            memo[i] = 1
        for i in range(len(nums) - 1, -1, -1):
            for j in range(i + 1, len(nums)):
                if nums[j] > nums[i]:
                    new = 1 + memo[j]
                    if new > memo[i]:
                        memo[i] = new
        return max(memo.values())