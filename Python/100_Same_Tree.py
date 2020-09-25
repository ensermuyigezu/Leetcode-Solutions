# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        x = self.inOrderTraversal(p, [])
        y = self.inOrderTraversal(q, [])
        return x == y
    
    def inOrderTraversal(self, r, ll):
        if r != None:
            if r.left == None and r.right != None:
                ll.append(None)
            else:
                self.inOrderTraversal(r.left, ll)
            ll.append(r.val)
            if r.right == None and r.left != None:
                ll.append(None)
            else:
                self.inOrderTraversal(r.right, ll)
        return ll
