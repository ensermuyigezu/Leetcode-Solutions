class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        k = 0
        visited = {}
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if (i, j) not in visited and grid[i][j] == '1':
                    self.BFS(grid, (i, j), visited)
                    k += 1            
        return k
    
    def BFS(self, G, s, visited):  
        queue = collections.deque()
        queue.append(s)
        visited[s] = True
        while queue:
            u = queue.popleft()
            for v in ((u[0], u[1]+1), (u[0]+1, u[1]), (u[0], u[1]-1), (u[0]-1, u[1])):
                if v not in visited and v[0] < len(G)  and v[0] >= 0 and v[1] < len(G[0]) and v[1] >= 0:
                    if G[v[0]][v[1]] == '1':
                        visited[v] = True
                        queue.append(v)
