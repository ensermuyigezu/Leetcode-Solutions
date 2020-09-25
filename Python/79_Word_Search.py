class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        parent = {}
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == word[0]:
                    x = self.DFS((i, j), board, word, 1, parent)
                    if x == True:
                        return True
        return False
    
    def DFS_Visit(self, s, graph, word, i, parent):
        if i == len(word):
            return True
        if i > len(word):
            return False
        for v in ((s[0], s[1] + 1), (s[0] + 1, s[1]), (s[0], s[1] - 1), (s[0] - 1, s[1])):
            if v not in parent and v[0] < len(graph) and v[0] >= 0 and v[1] < len(graph[0])and v[1] >= 0:
                if graph[v[0]][v[1]] == word[i]:
                    parent[v] = s
                    b = self.DFS_Visit(v, graph, word, i + 1, parent)
                    if b == True:
                        return True
                    del parent[v]

    def DFS(self, s, graph, word, i, parent):
        parent = {}
        parent[s] = None
        return self.DFS_Visit(s, graph, word, i, parent)
