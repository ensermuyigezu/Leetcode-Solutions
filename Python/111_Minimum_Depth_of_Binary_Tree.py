# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if root == None:
            return 0
        return self.minDepth1(root, 1)
    
    def minDepth1(self, root, i):
        if root.left == None and root.right == None:
            return i
        else:
            a = float('inf')
            b = float('inf')
            if root.left != None:
                a = self.minDepth1(root.left, i + 1)
            if root.right != None:
                b = self.minDepth1(root.right, i + 1)
            return min(a, b)
