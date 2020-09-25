class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        d = {}
        m = len(obstacleGrid[0])
        n = len(obstacleGrid)
        if m == 1 and n == 1:
            if obstacleGrid[0][0] == 1:
                return 0
            else:
                return 1
        a = max(m, n)
        for i in range(a):
            d[(i, -1)] = 0
            d[(-1, i)] = 0
        d[(0, 0)] = 1
        for i in range(n):
            for j in range(m):
                if i == 0 and j == 0 and obstacleGrid[i][j] != 1:
                    continue
                if obstacleGrid[i][j] == 1:
                    d[(i, j)] = float('inf')
                else:
                    d[(i, j)] = 0
                    if d[(i-1, j)] != float('inf'):
                        d[(i, j)] += d[(i-1, j)]
                    if d[(i, j-1)] != float('inf'):
                        d[(i, j)] += d[(i, j-1)]
        return 0 if d[(n-1, m-1)] == float('inf') else d[(n-1, m-1)]