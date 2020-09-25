class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        
        if len(nums) == 1:
            return []
        k = -2
        j = 0
        for i in range(len(nums)-2, -1, -1):
            if max(nums[i+1:]) > nums[i]:
                j = self.find_next_maximum(nums, i+1, len(nums)-1, nums[i])+i+1
                break
            k -= 1
        if (j == 0 and k >= -len(nums)) or k < -len(nums):
            nums.sort()
        else:
            nums[j], nums[k] = nums[k], nums[j]
            self.QuickSort(nums, len(nums)+k+1, len(nums)-1)
    
    def find_next_maximum(self, l, s, e, t):
        a = l[s:e+1]
        l = sorted(l[s:e+1])
        i = 0
        while l[i] <= t:
            i += 1
            if i > len(l) - 1:
                i -= 1
                break
        return a.index(l[i])
    
    def QuickSort(self, A, p, r):
        if p < r:
            q = self.Partition(A, p, r)
            self.QuickSort(A, p, q-1)
            self.QuickSort(A, q+1, r)
        return A

    def Partition(self, A, p, r):
        x = A[r]
        i = p - 1
        for j in range(p, r):
            if A[j] <= x:
                i += 1
                A[i], A[j] = A[j], A[i]
        A[i+1], A[r] = A[r], A[i+1]
        return i+1
