class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        if nums == []:
            return [[]]
        result = []
        for j in self.subsets(nums[1:]):
            result.append(j)
            result.append(j+[nums[0]])
        return result