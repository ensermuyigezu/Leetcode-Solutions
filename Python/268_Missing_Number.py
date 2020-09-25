class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        d = {}
        for i in nums:
            d[i] = True
        for i in range(len(nums)+1):
            if i not in d:
                return i