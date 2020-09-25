class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        a = self.binary_search(nums, target)
        b = self.binary_search1(nums, target)
        if a <= b:
            return [a, b]
        else:
            return [-1, -1]
        
    def binary_search(self, L, t):
        start = 0
        end = len(L)
        while start < end:
            mid = (start+end)//2
            if t <= L[mid]: end = mid
            elif t > L[mid]: start = mid + 1
        return start 
    
    def binary_search1(self, L, t):
        start = 0
        end = len(L)
        while start < end:
            mid = (start+end)//2
            if t < L[mid]: end = mid
            elif t >= L[mid]: start = mid + 1
        return start-1