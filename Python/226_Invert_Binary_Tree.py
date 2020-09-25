# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if root == None:
            return None
        if root.left == None and root.right == None:
            return root
        else:
            a = None
            b = None
            if root.left != None:
                a = self.invertTree(root.left)
            if root.right != None:
                b = self.invertTree(root.right)
            root.left, root.right = b, a
            return root