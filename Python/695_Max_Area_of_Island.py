class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        visited = {}
        x = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if (i, j) not in visited and grid[i][j] == 1:
                    a = self.BFS(grid, (i, j), visited)
                    if a > x:
                        x = a
        return x
    
    def BFS(self, G, s, visited):
        a = 1
        queue = collections.deque()
        queue.append(s)
        visited[s] = True
        while queue:
            u = queue.popleft()
            for v in (
                (u[0], u[1] + 1),
                (u[0] + 1, u[1]),
                (u[0], u[1] - 1),
                (u[0] - 1, u[1]),
            ):
                if (
                    v not in visited
                    and v[0] < len(G)
                    and v[0] >= 0
                    and v[1] < len(G[0])
                    and v[1] >= 0
                ):
                    if G[v[0]][v[1]] == 1:
                        visited[v] = True
                        a += 1
                        queue.append(v)
        return a