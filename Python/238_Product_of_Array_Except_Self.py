class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        a = []
        b = [0]*n
        a.append(1)
        a.append(nums[0])
        b[n-1] = 1
        b[n-2] = nums[n-1]
        for i in range(2, n):
            a.append(nums[i-1]*a[i-1])
        for j in range(n-3, -1, -1):
            b[j] = b[j+1] * nums[j+1]
        for i in range(n):
            nums[i] = a[i] * b[i]
        return nums