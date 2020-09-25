class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        d = [0]*(n+1)
        k = 0
        i = 0
        z = 0
        while i <= n-1:
            for j in range(z, n+1):
                x = j - ranges[j]
                y = j + ranges[j]
                if x <= i:
                    if y - i > d[i]:
                        d[i] = y - i
            if d[i] == 0:
                break
            i += d[i]
            z = i
        i = 0
        while i < len(d)-1:
            k += 1
            if d[i] == 0:
                return -1
            i += d[i]
        return k
    