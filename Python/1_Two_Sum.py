class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        d = {}
        for i in range(len(nums)):
            if nums[i] not in d:
                d[nums[i]] = [i]
            else:
                d[nums[i]].append(i)
        for i in range(len(nums)):
            if target-nums[i] in d:
                if target - nums[i] == nums[i]:
                    if len(d[target - nums[i]]) > 1:
                        return [d[nums[i]][0], d[nums[i]][1]]
                else:
                    return [i, d[target-nums[i]][0]]
        