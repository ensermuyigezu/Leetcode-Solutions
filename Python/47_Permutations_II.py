class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        d = {}
        for i in nums:
            if i in d:
                d[i] += 1
            else:
                d[i] = 1
        return self.perm(nums, [], d, [])
    def perm(self, l, current, d, e):
        if len(current) == len(l):
            e.append(current)
        else:
            for i in d:
                if d[i] != 0:
                    d[i] -= 1
                    self.perm(l, current+[i], d, e)
                    d[i] += 1
        return e