"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = []):
        self.val = val
        self.neighbors = neighbors
"""
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return None
        self.d = dict()
        self.s = set()
        self.dfs(node)
        return self.d[node.val]
    def dfs(self,node):
        if node.val not in self.d:
            self.d[node.val] = Node(node.val)
        for child in node.neighbors:
            if (node.val,child.val) in self.s:
                continue
            if child.val not in self.d:
                self.d[child.val] = Node(child.val)
            self.s.add((node.val,child.val))
            self.d[node.val].neighbors.append(self.d[child.val])
            self.dfs(child)