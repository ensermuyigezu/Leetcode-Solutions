class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = {}
        parent = {}
        for i in range(numCourses):
            graph[i] = []
        for edge in prerequisites:
            graph[edge[1]].append(edge[0])
        return self.DFS(graph, parent)
    
    def DFS(self, graph, parent):
        for s in graph.keys():
            if s not in parent:
                parent[s] = s
                a = self.DFS_Visit(s, graph, parent)
                del parent[s]
                if a:
                    return False
        return True
    
    def DFS_Visit(self, s, graph, parent):
        for v in graph[s]:
            if v in parent:
                return True
            else:
                parent[v] = s
                a = self.DFS_Visit(v, graph, parent)
                if a:
                    return True
                del parent[v]

    