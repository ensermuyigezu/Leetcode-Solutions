# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root == None:
            return 0
        return self.max_Depth(root, 1, 1)
    
    def max_Depth(self, root, i, l):
        if root.left == None and root.right == None:
            if i > l:
                l = i
            return l
        else:
            a = 0
            b = 0
            if root.left != None:
                a = self.max_Depth(root.left, i+1, l)
            if root.right != None:
                b = self.max_Depth(root.right, i+1, l)
            return max(a, b)