# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root == None:
            return True
        if root.left != None and root.right != None:
            return self.preOrder(root.left, []) == self.preOrder1(root.right, [])
        if root.left == None and root.right == None:
            return True
        return False
        
    def preOrder(self, root, d1):
        if root.left == None and root.right == None:
            d1 += [root.val, None, None]
        elif root.left != None and root.right != None:
            d1 += [root.val, root.left.val, root.right.val]
            self.preOrder(root.left, d1)
            self.preOrder(root.right, d1)
        elif root.left != None:
            d1 += [root.val, root.left.val, None]
            self.preOrder(root.left, d1)
        elif root.right != None:
            d1 += [root.val, None, root.right.val]
            self.preOrder(root.right, d1)
        return d1
    
    def preOrder1(self, root, d2):
        if root.left == None and root.right == None:
            d2 += [root.val, None, None]
        elif root.left != None and root.right != None:
            d2 += [root.val, root.right.val, root.left.val]
            self.preOrder1(root.right, d2)
            self.preOrder1(root.left, d2)
        elif root.left != None:
            d2 += [root.val, None, root.left.val]
            self.preOrder1(root.left, d2)
        elif root.right != None:
            d2 += [root.val, root.right.val, None]
            self.preOrder1(root.right, d2)
        return d2