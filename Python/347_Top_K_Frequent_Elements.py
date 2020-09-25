class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        d = {}
        for i in nums:
            if i not in d:
                d[i] = 1
            else:
                d[i] += 1
        l = []
        for i in range(len(d)+1):
            l.append([])
        for i in d:
            l[d[i] - 1].append(i)
        a = []
        for i in range(len(l) - 1, -1, -1):
            a += l[i]
        return a[0:k]