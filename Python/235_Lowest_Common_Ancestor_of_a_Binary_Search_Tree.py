# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        d = {}
        b = {}
        self.Search(root, p, d)
        self.Search(root, q, b)
        if len(d) <= len(b):
            for i in reversed(list(d.keys())):
                if i in b:
                    return d[i]
        else:
            for j in reversed(list(b.keys())):
                if j in d:
                    return d[j]
                
    def Search(self, root, x, m):
        m[root.val] = root
        while True:
            if x.val == root.val:
                m[root.val] = root
                break
            if x.val < root.val:
                root = root.left
                m[root.val] = root
            elif x.val > root.val:
                root = root.right
                m[root.val] = root