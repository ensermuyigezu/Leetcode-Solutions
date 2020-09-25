# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        return self.checkBST(root)
    
    def checkBST(self, root, minimum = None, maximum = None):
        if root == None:
            return True
        if (minimum != None and root.val <= minimum) or (
            maximum != None and root.val >= maximum
        ):
            return False
        if (not self.checkBST(root.left, minimum, root.val)) or (
            not self.checkBST(root.right, root.val, maximum)
        ):
            return False
        return True
    