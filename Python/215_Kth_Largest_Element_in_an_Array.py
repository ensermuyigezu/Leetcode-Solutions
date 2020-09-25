class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        return self.Randomized_Select(nums, 0, len(nums) - 1, len(nums) - k + 1)
    
    def Randomized_Select(self, A, p, r, i):
	    if p == r:
		    return A[p]
	    q = self.Randomized_Partition(A, p, r)
	    k = q - p + 1
	    if i == k:
		    return A[q]
	    elif i < k:
		    return self.Randomized_Select(A, p, q - 1, i)
	    else:
		    return self.Randomized_Select(A, q + 1, r, i - k)

    def Randomized_Partition(self, A, p, r):
        i = random.randint(p, r)
        A[i], A[r] = A[r], A[i]
        return self.Partition(A, p, r)

    def Partition(self, A, p, r):
        x = A[r]
        i = p - 1
        for j in range(p, r):
            if A[j] <= x:
                i += 1
                A[i], A[j] = A[j], A[i]
        A[i+1], A[r] = A[r], A[i+1]
        return i+1