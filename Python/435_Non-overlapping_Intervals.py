class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if intervals == []:
            return 0
        k = 1
        intervals.sort(key=lambda x: x[1])
        end = intervals[0][1]
        for interval in intervals:
            if interval[0] >= end:
                end = interval[1]
                k += 1
        return len(intervals) - k