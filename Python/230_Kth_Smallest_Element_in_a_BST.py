# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        x = self.inOrderTraversal(root, [])
        return x[k-1]
    
    def inOrderTraversal(self, r, ll):
        if r != None:
            if r.left != None:
                self.inOrderTraversal(r.left, ll)
            ll.append(r.val)
            if r.right != None:
                self.inOrderTraversal(r.right, ll)
        return ll

