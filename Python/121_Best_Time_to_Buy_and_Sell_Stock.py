class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        l = [0]
        for i in range(1, len(prices)):
            l.append(prices[i] - prices[i-1])
        return self.maxSubArray(l)
    
    def maxSubArray(self, nums):
        d = {}
        d[-1] = float('-inf')
        for i in range(len(nums)):
            s = max(nums[i], d[i-1] + nums[i])
            d[i] = s
        return max(d.values())