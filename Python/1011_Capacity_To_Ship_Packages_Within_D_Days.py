class Solution:
    def shipWithinDays(self, weights: List[int], D: int) -> int:
        lo, hi = max(weights), sum(weights)
        while lo < hi:
            mid = (lo+hi) // 2
            if self.helper(weights, D, mid):
                hi = mid
            else:
                lo = mid + 1
        return lo

    def helper(self,weights, D, k):
        days = 1
        tank = k
        for weight in weights:
            tank -= weight
            if tank < 0:
                days, tank = days+1, k-weight
        return days <= D