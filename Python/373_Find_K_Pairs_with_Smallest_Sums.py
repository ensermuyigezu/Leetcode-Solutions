class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        l = []
        for i in nums1:
            for j in nums2:
                l.append([i, j])
        l.sort(key=lambda x:x[0] + x[1])
        return l[:k]