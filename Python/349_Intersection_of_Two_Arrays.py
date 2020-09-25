class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        d = {}
        l = []
        for i in nums1:
            if i not in d:
                d[i] = 1
        for j in nums2:
            if j in d:
                l.append(j)
                del d[j]
        return l