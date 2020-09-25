class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        return self.perm(nums, [], [])
    def perm(self, l, current, order):
        if l == []:
            order += [current]
            return order
        else:
            for i in range(len(l)):
                self.perm(l[:i] + l[i+1:], current + [l[i]], order)
        return order