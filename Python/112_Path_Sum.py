# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if root == None:
            return False
        if root.left == None and root.right == None:
            return True if sum - root.val == 0 else False
        else:
            a = False
            b = False
            if root.left != None:
                a = self.hasPathSum(root.left, sum-root.val)
            if root.right != None:
                b = self.hasPathSum(root.right, sum-root.val)
        return a or b
