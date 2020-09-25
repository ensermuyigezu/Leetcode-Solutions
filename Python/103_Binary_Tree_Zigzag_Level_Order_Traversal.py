# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if root == None:
            return []
        dd = {}
        self.preOrderTraversal(root, 0, dd)
        ll = []
        for i in dd:
            ll += [dd[i]]
        a = False
        for i in ll:
            if a:
                i.reverse()
            a = not a
        return ll
        
    def preOrderTraversal(self, root, l, d):
        if root != None:
            if l not in d:
                d[l] = [root.val]
            else:
                d[l].append(root.val)
            if root.left != None:
                self.preOrderTraversal(root.left, l + 1, d)
            if root.right != None:
                self.preOrderTraversal(root.right, l + 1, d)
        return d