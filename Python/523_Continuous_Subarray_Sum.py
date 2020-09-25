class Solution(object):
    def checkSubarraySum(self, nums, k):
        b = {}
        b[0] = [nums[0]]
        for i in range(1, len(nums)):
            if k != 0 and (nums[i] + nums[i-1]) % k == 0 or k == 0 and nums[i] + nums[i-1] == 0:
                return True
            b[i] = []
            b[i].append(nums[i] + nums[i-1])
            for j in b[i-1]:
                ans = nums[i] + j
                if k != 0 and ans % k == 0:
                    return True
                if k == 0 and ans == 0:
                    return True
                b[i].append(ans)
        return False
                
        