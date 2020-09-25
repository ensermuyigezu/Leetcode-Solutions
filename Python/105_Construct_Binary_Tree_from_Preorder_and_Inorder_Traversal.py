# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if preorder == []:
            return None
        t = TreeNode(preorder[0])
        if inorder.index(preorder[0]) != 0:
            t.left = self.buildTree(
                preorder[1 : inorder.index(preorder[0]) + 1],
                inorder[: inorder.index(preorder[0]) + 1],
            )
        if inorder.index(preorder[0]) != len(preorder) - 1:
            t.right = self.buildTree(
                preorder[inorder.index(preorder[0]) + 1 :],
                inorder[inorder.index(preorder[0]) + 1 :],
            )
        return t