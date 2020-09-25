class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        d = {}
        a = max(m, n)
        for i in range(a):
            d[(i, -1)] = 0
            d[(-1, i)] = 0
        d[(0, 0)] = 1
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    continue
                else:
                    d[(i, j)] = 0
                    if d[(i-1, j)] != float('inf'):
                        d[(i, j)] += d[(i-1, j)]
                    if d[(i, j-1)] != float('inf'):
                        d[(i, j)] += d[(i, j-1)]
        return d[(m-1, n-1)]    