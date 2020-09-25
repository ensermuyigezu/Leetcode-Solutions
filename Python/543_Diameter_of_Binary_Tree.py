# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        if root == None:
            return 0
        return max(self.diameter(root))
    
    def diameter(self, root):
        if root == None:
            return [0, 0]
        if root.left == None and root.right == None:
            return [0, 0]
        else:
            a = [0, 0]
            b = [0, 0]
            if root.left != None:
                a = self.diameter(root.left)
            if root.right != None:
                b = self.diameter(root.right)
            if root.left != None and root.right != None:
                return (
                    max(a[0], b[0], a[1] + b[1] + 2),
                    max(a[1], b[1]) + 1,
                )
            return (
                max(a[0], b[0], a[1] + b[1] + 1),
                max(a[1], b[1]) + 1,
            )