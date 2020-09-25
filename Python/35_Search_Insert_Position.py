class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        start = 0
        end = len(nums)
        while start < end:
            mid = (start+end)//2
            if target <= nums[mid]: end = mid
            elif target > nums[mid]: start = mid + 1     
        return start