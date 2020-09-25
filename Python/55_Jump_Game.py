class Solution:
    def canJump(self, nums: List[int]) -> bool:
        x = len(nums)-1
        for i in range(len(nums)-2, -1, -1):
                if nums[i] + i >= x:
                    x = i
        return x == 0