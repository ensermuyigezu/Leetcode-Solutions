class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if intervals == []:
            return []
        intervals = sorted(intervals, key = lambda x:x[0])
        l = [intervals[0]]
        for i in range(1, len(intervals)):
            if intervals[i][0] <= l[-1][1]:
                if intervals[i][1] >= l[-1][1]:
                    l[-1][1] = intervals[i][1]
            else:
                l.append(intervals[i])        
        return l
