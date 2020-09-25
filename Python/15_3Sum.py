class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []
        e = {}
        d = {}
        if len(nums) < 3:
            return []
        for i in nums:
            if i not in e:
                e[i] = 1
            else:
                e[i] += 1
        if len(e) == 1 and len(nums) > 2 and nums[0] == 0:
            return [[nums[0],nums[0],nums[0]]]
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if -(nums[i] + nums[j]) in e:
                    if (nums[i] == -(nums[i] + nums[j]) and e[nums[i]] > 1) or (nums[j] == -(nums[i] + nums[j]) and e[nums[j]] > 1) or (nums[i] != -(nums[i] + nums[j]) and nums[j] != -(nums[i] + nums[j])):
                        if (nums[i] + nums[j] == 0 and e[0] > 2) or nums[i] != 0:
                            num = tuple(sorted([nums[i], nums[j], -(nums[i] + nums[j])]))   
                            if num not in d:
                                d[num] = 1
                                result.append([nums[i],  nums[j], -(nums[i] + nums[j])])
        return result