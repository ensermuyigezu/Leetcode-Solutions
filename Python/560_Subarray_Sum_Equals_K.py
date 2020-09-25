class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count = 0
        summ = 0
        d = {}
        d[0] = 1
        for i in range(len(nums)):
            summ += nums[i]
            if summ - k in d:
                count += d[summ-k]
            d[summ] = d.get(summ, 0) + 1
        return count
                