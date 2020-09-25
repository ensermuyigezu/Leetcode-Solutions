# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        if nums == []:
            return None
        return self.sortedArray(nums, 0, len(nums))
    
    def sortedArray(self, nums, left, right):
        if left >= right:
            return None
        mid = (left+right)//2
        a = TreeNode(nums[mid])
        a.left = self.sortedArray(nums, left, mid)
        a.right = self.sortedArray(nums, mid+1, right)
        return a