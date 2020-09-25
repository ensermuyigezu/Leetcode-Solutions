# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        a = self.preTraversal(s, []) 
        b = self.preTraversal(t, [])
        for i in range(len(a)):
            if a[i] == b[0] and b[:] == a[i:i+len(b)]:
                return True
        return False
    
    def preTraversal(self, r, ll):
        if r != None and r.left == None and r.right == None:
            ll.append(r.val)
            ll.append(None)
            ll.append(None)
        elif r != None:
            ll.append(r.val)
            if r.left == None and r.right != None:
                ll.append(None)
            else:
                self.preTraversal(r.left, ll)
            if r.right == None and r.left != None:
                ll.append(None)
            else:
                self.preTraversal(r.right, ll)
        return ll