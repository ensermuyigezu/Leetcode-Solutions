# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        if t1 != None and t2 != None:
            t = TreeNode(t1.val + t2.val)
            t.left = self.mergeTrees(t1.left, t2.left)
            t.right = self.mergeTrees(t1.right, t2.right)
            return t
        elif t1 != None:
            t = TreeNode(t1.val)
            t.left = self.mergeTrees(t1.left, t2)
            t.right = self.mergeTrees(t1.right, t2)
            return t
        elif t2 != None:
            t = TreeNode(t2.val)
            t.left = self.mergeTrees(t1, t2.left)
            t.right = self.mergeTrees(t1, t2.right)
            return t
